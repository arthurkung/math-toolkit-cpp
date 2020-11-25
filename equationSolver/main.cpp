#include <iostream>
#include "EquationSolver.h"

double simpleLinear(double x) { return 1.0 - 3.0 * x; }

int main()
{
    //funcPtr f{&simpleLinear};
    EquationSolver solver(&simpleLinear);
    std::cout << solver.evaluateFunc(2.0)<<"\n";
}
