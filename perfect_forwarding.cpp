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

void bar(A&&) {
    std::cout << "A&&\n";
}

void bar(A&) {
    std::cout << "A&\n";
}

template <typename T>
void foo(T&& t) {
    bar(std::forward<T>(t));
}

void baz(A&& t) {
    bar(t);
}

int main() {
    A x;
    foo(x); // x is deduced as A& (lvalue ref)
    foo(A()); // A() is deduced as A
    baz(x);
    baz(A());
}
