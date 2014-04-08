/*
 * test.cpp
 * Copyright (C) 2014 crozz <crozz@segv.sx>
 *
 * Distributed under terms of the GPLv3 license.
 *
 */
#include <unistd.h>
#include "RC4.h"

int main(int argc, char *argv[]){
	if(argc == 2){
		unsigned char *key;
		unsigned char c1[2];
		unsigned char c2[2];
		RC4 *cif;

		key = (unsigned char*)argv[1];
		cif = new RC4(key);


		while(read(0, c1, 1)){
			cif->cipher(c1, c2, 1);
			write(1, c2, 1);
		}

	delete cif;
	}
	else{
		write(1, "Try: ", 5);
		write(1, argv[0], sizeof(argv[0])+1);
		write(1, " <key>\n", 7);
	}

	return 0;
}
