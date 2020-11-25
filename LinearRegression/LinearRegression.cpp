#include <vector>
#include <iostream>
#include "LinearRegressor.h"

int main()
{
    LinearRegressor lr;

    //lr.m_x = { 1,2,3,4,5 };
    //lr.m_y = { 2,5,8,11,14 };
    //std::cout << lr.getConstTerm() << "\n";
    //std::cout << lr.getGradientWithConstTerm() << "\n";
    //std::cout << lr.getGradientWithoutConstTerm() << "\n";

    std::vector<double> hours{ 0.5,0.75,1.0,1.25,1.5,1.75,1.75,2.0,2.25,2.5,2.75,3.0,3.25,3.5,4.0,4.25,4.5,4.75,5.0,5.5 };
    std::vector<double> pass{ 0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,1.0,0.0,1.0,0.0,1.0,0.0,1.0,1.0,1.0,1.0,1.0,1.0};
    

}
