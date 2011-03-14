all: binding rvalue_lvalue rvo

binding: binding.cpp
	g++-mp-4.5 -O2 -W -Wall -pedantic -std=c++0x binding.cpp -o binding

rvalue_lvalue: rvalue_lvalue.cpp
	g++-mp-4.5 -O2 -W -Wall -pedantic -std=c++0x rvalue_lvalue.cpp -o rvalue_lvalue

rvo: rvo.cpp
	g++-mp-4.5 -O2 -W -Wall -pedantic -std=c++0x rvo.cpp -o rvo
