#include <iostream>
#include <memory>

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
        return *this;
    }

    A& operator=(A&& /* rhs */) {
        return *this;
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

void baz(A&& t) { // t is lvalue
    bar(t); // no way to perfect forward (call corresponding bar overload)
}



template <typename T, typename A>
inline
std::shared_ptr<T>
factory(A&& a) {
    return std::shared_ptr<T>(new T(std::forward<A>(a)));
}

template <typename T, typename A>
inline
std::shared_ptr<T>
factory_noforward(A&& a) {
    return std::shared_ptr<T>(new T(a));
}

struct B {
    B(int&) {
        std::cout << "B(int&)\n";
    }

    B(int&&) {
        std::cout << "B(int&&)\n";
    }
};

int make_int() {
    return 0;
}

int main() {
    A x; // lvalue

    bar(x);  // calls bar(A&)
    bar(A()); // calls bar(A&&)

    foo(x); // x is deduced as A& (lvalue ref) // bar(A&) is called
    foo(A()); // A() is deduced as A // bar(A&&) is called

    // baz(x); // error: invalid initialization of reference of type 'A&&' from expression of type 'A'
    baz(std::move(x)); // bar(A&) is called
    baz(A()); // bar(A&) is called

    int i = 0;
    factory<B>(i); // call B&
    factory<B>(make_int()); // call B&&
    factory_noforward<B>(i); // call B&
    factory_noforward<B>(make_int()); // call B&
}



