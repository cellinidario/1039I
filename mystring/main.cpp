#include <iostream>
#include "mystring.hpp"

int main(int, char**) {
    my::string r ("pippo");
    my::string s = std::move(r);
    r = std::move(s);
    std::cout << "s = " << s.c_str() << std::endl;
    std::cout << "size of s : " << s.size() << std::endl;
    std::cout << "r = " << r.c_str() << std::endl;
}
