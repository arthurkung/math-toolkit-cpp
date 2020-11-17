#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction a{ 1,6 };
    Fraction b{ 1,3 };
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << (a+=b) << "\n";
    std::cout << a << "\n";

    /*Fraction c;
    std::cout << "Enter a fraction: \n";
    std::cin >> c;
    std::cout << c << "\n";*/



    return 0;
}
