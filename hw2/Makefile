# Filename   :  Makefile2.txt
# Class      :  CS328 Spring 2013
# Assignment :  Program 1
# Programmer :  Kyle Jamison
# Date       :  2/3/2013

# This makefile will build an executable for the second example code.

CXX = /usr/bin/g++
FLAGS = -g -Wall -W -pedantic-errors

OBJECTS = driver.o

.SUFFIXES: .c .o .h .hpp

.cpp.o: $<
	${CXX} -c ${FLAGS} $< -o $@

default: all

all: driver

driver: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o $@

clean:
	-@rm -f driver > /dev/null 2>&1
	-@rm -f core > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1
