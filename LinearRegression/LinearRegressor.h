#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#ifndef LINEARREGRESSOR_H
#define LINEARREGRESSOR_H

class LinearRegressor {
public:
	std::vector<double> m_x{};
	std::vector<double> m_y{};
	double getGradientWithConstTerm();
	double getGradientWithoutConstTerm();
	double getConstTerm();
private:
	double getSxx() {
		return std::inner_product(m_x.begin(), m_x.end(), m_x.begin(), 0.0);
	}
	double getSx() {
		return std::accumulate(m_x.begin(), m_x.end(), 0.0);
	}
	double getSxy() {
		return std::inner_product(m_x.begin(), m_x.end(), m_y.begin(), 0.0);
	}
	double getSy() {
		return std::accumulate(m_y.begin(), m_y.end(), 0.0);
	}
	double getN() {
		return m_x.size();
	}
};

#endif