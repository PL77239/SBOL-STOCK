#pragma once
#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned long P[16 + 2];
  unsigned long S[4][256];
} BLOWFISH_CTX;

enum TYPE {
	TYPE_DECRYPT,
	TYPE_ENCRYPT
};

void Blowfish_Init(BLOWFISH_CTX *ctx, unsigned char *key, int keyLen);
void Blowfish_Encrypt(BLOWFISH_CTX *ctx, unsigned long *xl, unsigned long *xr);
void Blowfish_Decrypt(BLOWFISH_CTX *ctx, unsigned long *xl, unsigned long *xr);
void BFBufferEncrypt(char* input, unsigned long inputsize, unsigned char* key, unsigned long keysize);
void BFBufferDecrypt(char* input, unsigned long inputsize, unsigned char* key, unsigned long keysize);
void MakePS(BLOWFISH_CTX* ctx);