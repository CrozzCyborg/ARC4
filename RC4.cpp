/*
 * RC4.c
 * Copyright (C) 2014 crozz <crozz@segv.sx>
 *
 * Distributed under terms of the GPLv3 license.
 *
 */

#include "RC4.h"

RC4::RC4(unsigned char key[]){
	int key_len = sizeof(key);
	i = 0;
	j = 0;

	for(int x = 0;x < 256; x++) S[x] = x;

	ksa(key, key_len);
}

RC4::~RC4(){
	deletekey(S);
}

void RC4::ksa(unsigned char key[], int key_len){
	for(i = 0;i < 256;i++){
		j = (j + key[i % key_len] + S[i]) % 256;
		intercambio(i, j);
	}

	i = 0;
	j = 0;
}

unsigned char RC4::prga(){
	i = (i + 1) % 256;
	j = (j + S[i]) % 256;

	intercambio(i, j);

	return S[(S[i] + S[j]) % 256];
}

void RC4::cipher(unsigned char *text, unsigned char *text_cif, int text_len){
	unsigned char bk;

	for(int x = 0;x < text_len;x++){
		bk = prga();
		text_cif[x] = text[x]^bk;
	}
}

void RC4::intercambio(int x, int z){
	unsigned char tmp = S[x];
	S[x] = S[z];
	S[z] = tmp;
}

void RC4::deletekey(unsigned char *key){
	memset(&key, 0, sizeof(*key));
}

void RC4::deletekey(char *key){
	memset(&key, 0, sizeof(*key));
}
