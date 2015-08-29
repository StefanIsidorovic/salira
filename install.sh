#!/bin/bash

echo -e "\033[36m In order to build and compile Salira project you will need to have next libraries\033[0m"
echo -e "\033[33m 1. Qt5\033[0m"
echo -e "\033[33m 2. Flex & Bison (Yacc) \033[0m";
echo -e "\033[33m 3. Build Essentials (g++) \033[0m";
echo -e "\033[36m If you want to proceed with installation press Y, or N for termination? \033[0m";

# Read if user agreed to install libraries.
read -n 1 prompt
echo ""

# If yes install qt, flex and bison
if (( "$prompt" == "y"  ||  "$prompt" == "Y" ));
then
	echo -e "\033[1;29m Update repositories... \033[0m"
	sudo apt-get -qq update
	echo -e "\033[31m Installing Qt5....\033[0m"
	sudo apt-get -qq install qt5-default -y
	echo -e "\033[1;29m Installing build essentials... \033[0m"
	sudo apt-get -qq install build-essential -y
	echo -e "\033[32m Installing flex...\033[0m"
	sudo apt-get -qq install flex -y
	echo -e "\033[35m Installing yacc...\033[0m"
	sudo apt-get -qq install bison -y
fi

# All libraries are set (assumably) start with building project

# Create build directory
mkdir build

# Create MakeFile using qmake
echo -e "\033[1;33m running qmake... \033[0m"
cp src/Salira/* build/ -R
cd build
qmake Salira.pro

# Actual building
echo -e "\033[36m Actual building... \033[0m"
make >> logMake.txt 2>&1
mkdir parser

# Building and inserting parser
echo -e "\033[1;35m Mergining with parser... \033[0m"
cd ../src/parser/
make >> logMake.txt 2>&1
cp proba ../../build/parser/proba
cd ../../build/

# Starting project
./Salira


​
