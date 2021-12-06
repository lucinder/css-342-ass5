#!/bin/bash

# To more easily compile and run this program on CSS Linux Lab
# Lines starting with '$' indicate what is typed on command line

# if you get the following error:
# -bash: ./simplecompile.sh: /bin/bash^M: bad interpreter: No such file or directory
# run dos2unix to fix it
# $ dos2unix simplecompile.sh

# make this file executable
# $ chmod 700 simplecompile.sh
# redirect the output and stderr from this file to output.txt
# $ ./simplecompile.sh > output.txt 2>&1
#TO ENABLE CLANGTIDY do this EVERYTIME on linux lab: scl enable llvm-toolset-7.0 bash

date

echo
echo "*** compiling with clang++ to create an executable called main"
clang++ --version
clang++ -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp threadedbst.cpp -g -o main

# echo "*** running clang-tidy using options from .clang-tidy"
clang-tidy --version
clang-tidy *.cpp -- -std=c++11

echo
echo "*** running main"
./main

# valgrind will detect memory leaks
# echo "*** running with valgrind"
# valgrind --leak-check=full ./main.exe

# echo
# echo "*** cleaning up, deleting main"
# rm main

echo
date