#!/bin/bash
g++ -c -Wall -Wconversion -Wextra -Wpedantic CPP\ Lab\ 1\ -\ 2021.cpp && g++ -c string.h
g++ CPP\ Lab\ 1\ -\ 2021.o string.h -o Lab2
./Lab2
