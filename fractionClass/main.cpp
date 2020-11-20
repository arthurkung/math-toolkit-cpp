#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction a{ 1,6 };
    Fraction b{ -1,3 };
    //int a{1};
    //int b{2};
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << (a>b) << "\n";
    std::cout << b["numerator"] << "\n";
    std::cout << static_cast<float>(b) << "\n";

    /*Fraction c;
    std::cout << "Enter a fraction: \n";
    std::cin >> c;
    std::cout << c << "\n";*/



    return 0;
}
