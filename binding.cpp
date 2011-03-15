#include <string>

const std::string const_rvalue() {
    return "";
}

std::string rvalue() {
    return "";
}

std::string lvalue = "";

const std::string const_lvalue = "";

int main() {
    /// lvalue refs

    // std::string& lvalue_ref_1 = const_rvalue(); // error
    // std::string& lvalue_ref_2 = rvalue(); // error
    // std::string& lvalue_ref_3 = const_lvalue; // error
    std::string& lvalue_ref_4 = lvalue; // ok

    /// const lvalue refs

    const std::string& const_lvalue_ref_1 = const_rvalue(); // ok
    const std::string& const_lvalue_ref_2 = rvalue(); // ok
    const std::string& const_lvalue_ref_3 = const_lvalue; // ok
    const std::string& const_lvalue_ref_4 = lvalue; // ok

    /// rvalue refs

    // std::string&& rvalue_ref_1 = const_rvalue(); // error
    std::string&& rvalue_ref_2 = rvalue(); // ok
    // std::string&& rvalue_ref_3 = const_lvalue; // error
    std::string&& rvalue_ref_4 = lvalue; // ok

    /// const rvalue refs

    const std::string&& const_rvalue_ref_1 = const_rvalue(); // ok
    const std::string&& const_rvalue_ref_2 = const_rvalue(); // ok
    const std::string&& const_rvalue_ref_3 = const_lvalue; // ok
    const std::string&& const_rvalue_ref_4 = lvalue; // ok
}
