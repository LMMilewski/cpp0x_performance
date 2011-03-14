# CC=g++-mp-4.5
CC=g++
CPPFLAGS=-O2 -W -Wall -pedantic -std=c++0x
CPP=$(wildcard *.cpp)
ALL=binding rvalue_lvalue rvo

all: $(ALL)

%: %.cpp
	$(CC) $(CPPFLAGS) $^ -o $@
