#include "main.h"
#include "blowfish.h"


int main(int argc, char** argv) {
	try
	{
		int type = -1;
		std::string cipherkey, infilename, outfilename;
		std::cout << "Starting..." << std::endl;

		for (int i = 0; i < argc; i++)
		{
			if (argv[i][0] == '/' || argv[i][0] == '-')
			{
				if (toLower(std::string(argv[i] + 1)) == "d")
				{
					if (type != -1) throw "Invalid usage";
					type = TYPE_DECRYPT;
				}
				else if (toLower(std::string(argv[i] + 1)) == "e")
				{
					if (type != -1) throw "Invalid usage";
					type = TYPE_ENCRYPT;
				}
				else if (toLower(std::string(argv[i] + 1)) == "k")
				{
					if (!cipherkey.empty() && (i + 2) < argc) throw "Invalid usage";
					cipherkey = argv[i + 1];
					i++;
				}
				else if (toLower(std::string(argv[i] + 1)) == "i")
				{
					if (!infilename.empty() && (i + 2) < argc) throw "Invalid usage";
					infilename = argv[i + 1];
					i++;
				}
				else if (toLower(std::string(argv[i] + 1)) == "o")
				{
					if (!outfilename.empty() && (i + 2) < argc) throw "Invalid usage";
					outfilename = argv[i + 1];
					i++;
				}
			}
		}

		if (type == -1 || cipherkey.empty() || infilename.empty() || outfilename.empty()) throw "Invalid usage";

		unsigned char* filekey = NULL;
		size_t filekeysize = 0;
		char* fileBuf = NULL;
		size_t size;
		filekey = (unsigned char*)(cipherkey.data());
		filekeysize = cipherkey.size();
		if (type == TYPE_DECRYPT) // Decrypt
		{
			if ((size = loadFile(infilename.c_str(), &fileBuf)) > 0)
			{
				BFBufferDecrypt(fileBuf, size, filekey, filekeysize);
				if (*(unsigned long*)&fileBuf[0x00] > size)
				{
					std::cout << "Error decrypting file to " << infilename << std::endl;
					return 1;
				}
				size_t decryptedsize = *(size_t*)&fileBuf[0x00];
				unsigned long check = *(unsigned long*)&fileBuf[0x04];
				fileBuf += 8;
				size -= 8;
				
				if (saveFile(fileBuf, decryptedsize, outfilename.c_str()) < 1 && decryptedsize > size)
				{
					std::cout << "Error saving decrypted file to " << outfilename << std::endl;
					return 1;
				}
				else
				{
					std::cout << infilename << " decrypted successfully. " << size << "bytes in total" << std::endl;
					std::cout << "Checksum: " << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << check << std::endl;
					return 0;
				}
			}
			else
			{
				std::cout << "Error loading file " << infilename;
				return 1;
			}
		}
		else if (type == TYPE_ENCRYPT) // Encrypt
		{
			if ((size = loadFile(infilename.c_str(), &fileBuf)) > 0)
			{
				unsigned long check = createCheckSum(&fileBuf[0x00], size);
				if (size % 8)
					size += 8 - (size % 8);
				size_t outfilesize = size;
				char* encryptBuf;
				outfilesize += 0x08; // file size and checksum
				encryptBuf = (char*)calloc(1, outfilesize);
				if (!encryptBuf)
				{
					std::cout << "Error allocating " << size << "bytes for encrypted file. Out of memory." << std::endl;
					return 1;
				}

				int offset = 0;
				int encryptOffset = offset;
				*(unsigned long*)&encryptBuf[offset] = size;
				offset += 4;
				*(unsigned long*)&encryptBuf[offset] = check;
				offset += 4;
				memcpy(&encryptBuf[offset], &fileBuf[0], size);

				BFBufferEncrypt(&encryptBuf[encryptOffset], size + 8, filekey, filekeysize);
				if (saveFile(encryptBuf, outfilesize, outfilename.c_str()) < 1)
				{
					std::cout << "Error saving encrypted file to " << outfilename << std::endl;
					return 1;
				}
				else
				{
					std::cout << infilename << " encrypted successfully. " << size << "bytes in total" << std::endl;
					std::cout << "Checksum: " << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << check << std::endl;
					return 0;
				}
			}
		}
		else
			throw "Invalid usage";
	}
	catch(...)
	{
		std::string path = argv[0];
		std::string executable;
		size_t pos = path.find_last_of('\\');
		if (pos != std::string::npos) executable = path.substr(pos + 1);
		else executable = path;

		std::cout << "  Usage: \"" << executable << "\" -[d/e] -k \"<cipherkey>\" -i \"<infile>\" -o \"<outputfile>\"" << std::endl;
		std::cout << "    -d Decrypt file." << std::endl;
		std::cout << "    -e Encrypt file." << std::endl;
		std::cout << "    -k Cipher key." << std::endl;
		std::cout << "    -i File to be encrypted or decrypted." << std::endl;
		std::cout << "    -o Resulting file of encryption or decryption." << std::endl;
		return 0;
	}
}

