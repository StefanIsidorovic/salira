#!/bin/bash

rm -R -f build &> log
cd src/parser/ &> log
rm -f proba *.o *.txt &> log
rm -f gcode.txt tree.txt lambda.tab.c proba lambda.output lambda.tab.h lex.yy.cc &> log
rm -f log
