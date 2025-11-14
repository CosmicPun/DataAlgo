#include <stdexcept>
#include <iostream>
#include "pair.h"
#include "student.h"
#include <string>


int main() {
    int fa,fb;
    std::string sa,sb;
    std::cin >> fa >> sa;
    std::cin >> fb >> sb;

    CP::pair<int,std::string> a(fa,sa), b(fb,sb);

    std::cout << "Result of a >= b is " << (a >= b) << std::endl;
    std::cout << "Result of b >= a is " << (b >= a) << std::endl;
}
