/*
 * RC4.h
 * Cryptographic Library with ARC4 algorithm
 *
 * Copyright (C) 2014 crozz <crozz@segv.sx>
 *
 * Distributed under terms of the GPLv3 license.
 *
 */

#ifndef RC4_H
#define RC4_H 1

#include <cstring>

class RC4{
	public:
		RC4(unsigned char[]);
		~RC4();
		void cipher(unsigned char*, unsigned char*, int);
		void deletekey(unsigned char*);
		void deletekey(char*);

	private:
		int i,j;
		unsigned char S[256];

		void intercambio(int, int);
		void ksa(unsigned char[], int);
		unsigned char prga();
};

#include "RC4.c"

#endif /* !RC4_H */
