#include <iostream>
#include "EquationSolver.h"

double simpleLinear(double x) { return 1.0 - 3.0 * x; }

int main()
{
    //funcPtr f{&simpleLinear};
    //EquationSolver solver(&f);


    //EquationSolver solver([](double x) -> double {
    //    return 1.0 - 3.0 * x;
    //    });

    //auto linear{
    //    [](double x) {return 1.0 - 3.0 * x;}
    //};
    //EquationSolver solver (linear);


    EquationSolver solver(&simpleLinear);
    std::cout << solver.evaluateFunc(2.0)<<"\n";
}
