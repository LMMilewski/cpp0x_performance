
const int const_rvalue() {
    return 0;
}

int rvalue() {
    return 0;
}

int lvalue = 0;

const int const_lvalue = 0;

int main() {
    /// lvalue refs

    // int& lvalue_ref_1 = const_rvalue(); // error
    // int& lvalue_ref_2 = rvalue(); // error
    // int& lvalue_ref_3 = const_lvalue; // error
    int& lvalue_ref_4 = lvalue; // ok

    /// const lvalue refs

    const int& const_lvalue_ref_1 = const_rvalue(); // ok
    const int& const_lvalue_ref_2 = rvalue(); // ok
    const int& const_lvalue_ref_3 = const_lvalue; // ok
    const int& const_lvalue_ref_4 = lvalue; // ok

    /// rvalue refs

    // int&& rvalue_ref_1 = const_rvalue(); // error
    // int&& rvalue_ref_2 = rvalue(); // ok
    // int&& rvalue_ref_3 = const_lvalue; // error
    // int&& rvalue_ref_4 = lvalue; // ok

    /// const rvalue refs

    int&& const_rvalue_ref_1 = const_rvalue(); // ok
    int&& const_rvalue_ref_2 = const_rvalue(); // ok
    int&& const_rvalue_ref_3 = const_lvalue; // ok
    int&& const_rvalue_ref_4 = lvalue; // ok
}
