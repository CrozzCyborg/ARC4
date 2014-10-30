#
# Makefile
# crozz, 2014-10-29 20:16
#

CC = g++
CFLAGS = -Wall

all: test

library:
	${CC} ${CFLAGS} -c RC4.cpp -o RC4.o

test: library
	${CC} ${CFLAGS} -o ARC4 RC4.o test.cpp
	rm RC4.o

install_test: test
	cp -f ARC4 /usr/bin/ARC4
	cp -f RC4.sh /usr/bin/RC4
	chmod 755 /usr/bin/ARC4
	chmod 755 /usr/bin/RC4

# vim:ft=make
#
