#!/usr/bin/env bash

g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o logger.o "logger.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o strprintf.o "strprintf.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o input.o "input.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o arguments.o "arguments.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o utils.o "utils.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o JWAcalc.o "JWAcalc.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o dex.o "dex.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o stats.o "stats.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o expression.o "expression.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o ability.o "ability.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o modifiers.o "modifiers.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o dino.o "dino.cpp" 
g++ -std=c++17 -O3 -Wall -c -fmessage-length=0 -fopenmp -o actions.o "actions.cpp" 
g++ -static -static-libstdc++ -static-libgcc -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -fopenmp -o JWAcalc JWAcalc.o ability.o actions.o arguments.o dex.o dino.o expression.o input.o logger.o modifiers.o stats.o strprintf.o utils.o 
