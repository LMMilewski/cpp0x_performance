#include <string>
#include <iostream>

struct A {
    explicit A(const std::string& value)
        : value(value) {
        std::cout << "\tconstructor " << value << "\n";
    }

    A(const A& src)
        : value(src.value) {
        std::cout << "\tcopy constructor " << value << "\n";
    }

    ~A() {
        std::cout << "\tdestuctor " << value << "\n";
    }

    std::string value;
};

A rvo_nothrow() {
    return A("rvo_nothrow");
}

A nrvo_nothrow() {
    A result("nrvo_nothrow");
    return result;
}

A nrvo_throw() {
    A result("nrvo_throw");
    throw "happy exception\n";
    return result;
}


// nrvo won't work because it has to track which object need to be
// destructed
//
// if we didn't define destructor for A then nrvo would work in this
// case
A nrvo_branch(bool a) {
    A result_a("nrvo_branch a");
    A result_b("nrvo_branch b");

    if (a) {
        return result_a;
    }
    else {
        return result_b;
    }
}

A nrvo_clever_branch(bool a) {
    A result("<unknown>");
    if (a) {
        result.value = "nrvo_clever_branch a";
    }
    else {
        result.value = "nrvo_clever_branch a";
    }
    return result;
}


int main() {
    std::cout << "rvo_nothrow\n";
    A a = rvo_nothrow();
    std::cout << "nrvo_nothrow\n";
    A b = nrvo_nothrow();
    std::cout << "nrvo_throw\n";
    try {
        A c = nrvo_throw();
    }
    catch (char* msg) {
        std::cout << "got exception: " << msg << "\n";
    }
    std::cout << "nrvo_branch\n";
    A d =nrvo_branch(true);
    std::cout << "nrvo_clever_branch\n";
    A e = nrvo_clever_branch(true);
    std::cout << "done\n";
}
