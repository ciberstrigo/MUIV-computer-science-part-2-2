#!/bin/bash
gcc --std=c89 -fPIC ex3.c -shared -o bst.so
gcc --std=c89 -o test test.c ./bst.so
./test
