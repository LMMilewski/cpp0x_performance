#include <iostream>
#include <string>


const std::string const_rvalue() {
    return "const_rvalue";
}

std::string rvalue() {
    return "rvalue";
}

std::string lvalue = "lvalue";

const std::string const_lvalue = "const_lvalue";



void foo(const std::string& value) {
    std::cout << value << "\tfoo(const std::string&)\n";
}

void foo(std::string& value) {
    std::cout << value << "\tfoo(std::string&)\n";
}

void foo(const std::string&& value) {
    std::cout << value << "\tfoo(const std::string&&)\n";
}

void foo(std::string&& value) {
    std::cout << value << "\tfoo(std::string&&)\n";
}


void bar(std::string&& value) {
    std::cout << value << "\tbar(std::string&&)\n";
}

void bar(std::string& value) {
    std::cout << value << "\tbar(std::string&)\n";
}



void baz(std::string&& value) {
    std::cout << value << "\tbaz(std::string&&)\n";
}

int main() {
    foo(const_rvalue());
    foo(rvalue());
    foo(const_lvalue);
    foo(lvalue);

    std::cout << "\n";

    // bar(const_rvalue()); // error: no matching function for call to ‘bar(const std::string)’
    bar(rvalue());
    // bar(const_lvalue); // error: no matching function for call to ‘bar(const std::string&)’
    bar(lvalue);

    std::cout << "\n";

    // baz(const_rvalue()); // invalid initialization of non-const reference of type ‘std::string&&’ from a temporary of type ‘const std::string’
    baz(rvalue());
    // baz(const_lvalue); // error: invalid initialization of reference of type ‘std::string&&’ from expression of type ‘const std::string’
    baz(lvalue);
}
