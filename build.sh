#!/bin/bash

function checkIfFailed { 
	if [[ $? == 1 ]] 
	then
		echo -e "\033[1m \033[31m $1 \033[0m"
		exit 1
	fi
}

rm log &> log

echo -e "\033[1m \033[36m In order to build and compile Salira project you will need to have next libraries\033[0m"
echo -e "\033[1m \033[33m 1. Qt5\033[0m"
echo -e "\033[1m \033[33m 2. Flex & Bison (Yacc) \033[0m";
echo -e "\033[1m \033[33m 3. Build Essentials (g++) \033[0m";
echo -e "\033[1m \033[36m If you want to proceed with installation press Y, or anything else for termination? \033[0m";

# Read if user agreed to install libraries.
read -n 1 -r
echo

# If yes install qt, flex and bison
if [[ $REPLY =~ ^[Yy]$ ]]
then
	# Check and install qt5-default
	dpkg -s qt5-default 		&> log
	if [[ $? -eq 1 ]] 
	then
		echo -e "\033[1m \033[36m Package qt5-default missing. \033[0m"
		echo -e "\033[1m \033[36m Installing Qt5....\033[0m"
		sudo apt-get -qq install qt5-default -y &> log
		
		# if install is successful
		if [[ $? -eq 1 ]] 
		then
			echo -e "\033[1m \033[31m Install of qt5-default unsuccessful. \033[0m"
			exit 1
		fi
		echo -e "\033[1m \033[32m Install of qt5-default successful. \033[0m"
	fi
	
	# Check and install bison
	dpkg -s bison 					&> log
	if [[ $? -eq 1 ]] 
	then
		echo -e "\033[1m \033[36m Package bison missing. \033[0m"
		echo -e "\033[1m \033[36m Installing yacc...\033[0m"
		sudo apt-get -qq install bison -y &> log
		if [[ $? -eq 1 ]] 
		then
			echo -e "\033[1m \033[31m Install of bison unsuccessful.\033[0m"
			exit 1
		fi
		echo -e "\033[1m \033[32m Install of bison successful.\033[0m"
	fi

	# Check and install flex
	dpkg -s flex  					&> log
	if [[ $? -eq 1 ]] 
	then
		echo -e "\033[1m \033[36m Package flex missing. \033[0m"
		echo -e "\033[1m \033[36m Installing flex...\033[0m"
		sudo apt-get -qq install flex -y &> log
		if [[ $? -eq 1 ]] 
		then
			echo -e "\033[1m \033[31m Install of flex unsuccessful. \033[0m"
			exit 1
		fi
		echo -e "\033[1m \033[32m Install of flex successful. \033[0m"
	fi

	# Check and install build-essential
	dpkg -s build-essential &> log
	if [[ $? -eq 1 ]] 
	then
		echo -e "\033[1m \033[36m Package build-essential missing. \033[0m"
		echo -e "\033[1m \033[36m Installing build essentials... \033[0m"
		sudo apt-get -qq install build-essential -y > log
		if [[ $? -eq 1 ]] 
		then
			echo -e "\033[1m \033[31m Install of build-essential unsuccessful. \033[0m"
			exit 1
		fi
		echo -e "\033[1m \033[32m Install of build-essential successful. \033[0m"
	fi
else
	echo -e "\033[1m \033[31m Exiting... \033[0m"
	exit
fi

# Clean all build directories if exists
rm -R -f build &> log
cd src/parser
rm -f gcode.txt tree.txt lambda.tab.c proba lambda.output lambda.tab.h lex.yy.cc &> log
cd ../..

# Create build directory
mkdir build
checkIfFailed "unsuccessful creation of build directory. "

# Create MakeFile using qmake
echo -e "\033[1m \033[36m running qmake... \033[0m"
cp src/Salira/* build/ -R
checkIfFailed "Unsuccessful copying of Salira src files into build directory. "
cd build
qmake Salira.pro &> log
checkIfFailed "Qmake failed. Check log."

# Actual building
echo -e "\033[1m \033[36m Actual building... \033[0m"
make >> logMake.txt 2>&1
checkIfFailed "Building of Salira Qt project failed."
mkdir parser

# Building and inserting parser
echo -e "\033[1m \033[36m Mergining with parser... \033[0m"
cd ../src/parser/
make >> logMake.txt 2>&1
checkIfFailed "Building of parser failed."
cp proba ../../build/parser/proba
checkIfFailed "Copying parser failed."
# Clean build of parser
rm -f gcode.txt tree.txt lambda.tab.c proba lambda.output lambda.tab.h lex.yy.cc &> log
cd ../../build/

echo -e "\033[1m \033[32m Building of Salira Project successful! \033[0m"