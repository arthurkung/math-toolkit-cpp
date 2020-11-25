#include <utility>

#ifndef EQUATIONSOLVER_H
#define EQUATIONSOLVER_H

using funcPtr = double(*)(double);


class EquationSolver
{
public:
	EquationSolver(funcPtr f):m_func(f)
	{
		
	}
	funcPtr m_func;

	double evaluateFunc(double x) { return m_func(x); }
	double solveByBisection(double,std::pair<double, double>);


private:

};


#endif
