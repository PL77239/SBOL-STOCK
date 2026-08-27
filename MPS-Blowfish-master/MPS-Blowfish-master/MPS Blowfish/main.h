#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <chrono>

std::string toLower(std::string str)
{
	std::string out;
	for (auto elem : str)
		out += tolower(elem);
	return out;
}
int loadFile(const char* filepath, char** filebuffer)
{
	FILE* fp;
	auto res = fopen_s(&fp, filepath, "rb");
	if (res)
	{
		std::cout << "Error loading file " << filepath << std::endl;
		return 0;
	}

	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	rewind(fp);

	*filebuffer = (char*)calloc((size / 32) + 1, 32);
	if (!*filebuffer)
	{
		std::cout << "Error allocating memory for file" << std::endl;
		return 0;
	}
	fread(*filebuffer, size, 1, fp);
	fclose(fp);
	return size;
}
int saveFile(char* fileBuf, unsigned long size, const char* outfilename)
{
	FILE* fp;
	if (fileBuf == NULL || size == 0 || outfilename == NULL)
		return -1;
	auto res = fopen_s(&fp, outfilename, "wb");
	if (res)
		return -2;
	auto savesize = fwrite(fileBuf, size, 1, fp);
	fclose(fp);
	if (savesize < 1)
		return -3;
	else
		return savesize;
}
int verifyCheckSum(unsigned long CheckSum, char* buf, unsigned long size)
{
	unsigned long thisCheckSum = 0;
	for (unsigned int i = 0; i < ((size + (4 - (size % 4))) / 4); i++)
	{
		thisCheckSum ^= *(unsigned long*)&buf[i * 4];
	}
	if (thisCheckSum == CheckSum)
		return 0;
	else
		return thisCheckSum;
}
unsigned long createCheckSum(char* buf, unsigned long size)
{
	unsigned long thisCheckSum = 0;
	unsigned long remainder = size & 3;
	for (unsigned int i = 0; i < (size  / 4); i++)
	{
		thisCheckSum ^= *(unsigned long*)&buf[i * 4];
	}
	for (unsigned int i = 0; i < remainder; i++)
	{
		thisCheckSum ^= buf[((size / 4) * 4) + i];
	}
	return thisCheckSum;
}
