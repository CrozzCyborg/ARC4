#!/bin/bash
#
# RC4.sh
# Copyright (C) 2014 crozz <crozz@segv.sx>
#
# Distributed under terms of the GPLv3 license.
#

if [[ $# -lt 3 ]]; then
	echo "Try: $0 <c|d> <password> <text>";
	exit
fi

if [[ $1 == 'c' ]]; then
	echo "$3" | ARC4 $2 | base64;
elif [[ $1 == 'd' ]]; then
	echo "$3" | base64 -d | ARC4 $2;
elif [[ $1 == 'f' ]]; then
	cat "$3" | ARC4 $2 > "$3.4";
else
	echo "Try: $0 <c|d> <password> <text>";
fi
