#include <vector>
#include <iostream>
#include "LinearRegressor.h"

int main()
{
    LinearRegressor lr;

    lr.m_x = { 1,2,3,4,5 };
    lr.m_y = { 2,5,8,11,14 };
    std::cout << lr.getConstTerm() << "\n";
    std::cout << lr.getGradientWithConstTerm() << "\n";
    std::cout << lr.getGradientWithoutConstTerm() << "\n";
}
