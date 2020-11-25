#include "EquationSolver.h"
#include <utility>

double EquationSolver::solveByBisection(double tolerance, std::pair<double, double> range) {
	
	double mid{};
	bool isRootOnRight{};
	while (std::get<1>(range) - std::get<0>(range) > tolerance) {
		mid = (std::get<0>(range) + std::get<1>(range)) / 2;
		isRootOnRight = (evaluateFunc(std::get<0>(range)) > 0) == (evaluateFunc(mid) > 0);
		range = (isRootOnRight) ? std::make_pair(mid, std::get<1>(range)) : std::make_pair(std::get<0>(range), mid);
	}
	
	return (std::get<0>(range) + std::get<1>(range)) / 2;
	
}