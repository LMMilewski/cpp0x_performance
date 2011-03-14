int five() {
    return 5;
}

int g_five = 5;
int& five_ref() {
    return g_five;
}

void weird(const int& x) {
    const int* y = &x; // that's ok, so x is lvalue! (even if bound to temporary!) 
}

int main() {
    int a = 0;
    int* pa = 0;
    pa = &a; // ok, pa is lvalue
    *pa = 1; // ok, *pa is lvalue

    int b = *pa; // hey! isn't *pa lvalue? well, there is a conversion lvalue -> rvalue
    // 5 = b; // error! 5 is rvalue

    five_ref() = 3; // ok! lvalue
    // five()  = 4; // error! rvalue

    int x = 0;
    ++x = 1; // this is ok (++x is lvalue)
    // x++ = 2; // this fails (x++ is not lvalue - it returns a temporary)

    weird(3);
}
