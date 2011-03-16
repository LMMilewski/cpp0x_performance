#include <iostream>

struct A {
    int value;

    A()
        : value(0) {
    }

    A(const A& /* rhs */) {
        std::cout << "copying (ctor)\n";
    }

    A(A&& /* rhs */) {
    }

    A& operator=(const A& /* rhs */) {
        std::cout << "copying (operator)\n";
    }

    A& operator=(A&& /* rhs */) {

    }
};

A make_a() {
    return A();
}

int main() {
    A a;
    A b = a; // copying
    b = a; // copying
    A c = std::move(a); // no copying
    c = std::move(b); // no copying

    A&& rc = std::move(c); // std::move is mandatory
    A d = rc; // *named* rvalue reference is a lvalue! This will copy
    A e = make_a(); // *unnamed* rvalue reference is rvalue. No copying!
}
