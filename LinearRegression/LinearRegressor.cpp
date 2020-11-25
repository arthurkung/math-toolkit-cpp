#include "LinearRegressor.h"

double LinearRegressor::getGradientWithConstTerm() {
	double n{ getN() };
	double sxy{ getSxy() };
	double sxx{ getSxx() };
	double sx{ getSx() };
	double sy{ getSy() };
	return (n * sxy - sx * sy) / (n * sxx - sx * sx);
}
double LinearRegressor::getConstTerm() {
	double n{ getN() };
	double sxy{ getSxy() };
	double sxx{ getSxx() };
	double sx{ getSx() };
	double sy{ getSy() };
	return (sy * sxx - sxy * sx) / (n * sxx - sx * sx);
}
double LinearRegressor::getGradientWithoutConstTerm() {
	return getSxy()/getSxx();
}