ARC4
====

Cryptographic Library with ARC4 algorithm.

Library
-------

The Library is only two archives RC4.cpp and RC4.h, the rest of files are only to test the library.

Test
----

You may test the library by using the file test.cpp and make.

Run "make" to compile the file test.cpp and use it as follow:
>	cat archive_to_cipher | ARC4 theKey > archive_cipher

You can also perform a "make install_test" which installs the file RC4.sh and the binary-file ARC4 to /usr/bin and provides you the RC4 command, that can be used as follows.
>	RC4 <c|d> <password> <text>

This command is used to encrypt any <text> with the <password> and get an output cipher in RC4 and encoded in base64.
