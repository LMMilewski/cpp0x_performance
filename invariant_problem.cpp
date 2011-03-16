// source: http://cpp-next.com/archive/2010/10/implicit-move-must-go/

#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>

struct X
{
    // invariant: v.size() == 5
    X() : v(5) {}

    ~X()
    {
        std::cout << v[0] << std::endl;
    }

 private:
    std::vector<int> v;
};

int main()
{
    std::vector<X> y;
    y.push_back(X()); // X() rvalue: copied in C++03, moved in C++0x
}
