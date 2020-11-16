#include <algorithm>
#include <iostream>
#include "Fraction.h"

void Fraction::simplify() {
    if (m_num == 0)
    {
        m_denom = 1;
    }
    else
    {
        int HCF{ findHCF() };
        m_num /= HCF;
        m_denom /= HCF;
        if (m_denom < 0)
        {
            m_num *= -1;
            m_denom *= -1;
        }
    }
    
}

int Fraction::findHCF() {
    int num{ std::abs(m_num) };
    int denom{ std::abs(m_denom) };
    int a{ std::min(num, denom) };
    int b{ std::max(num, denom) };
    int remainder{ b % a };
    while (remainder) {
        b = a;
        a = remainder;
        remainder = b % a;
    }

    return a;
}
Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.m_num*f2.m_denom + f2.m_num*f1.m_denom,f1.m_denom* f2.m_denom);
}
Fraction operator-(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.m_num * f2.m_denom - f2.m_num * f1.m_denom, f1.m_denom * f2.m_denom);
}
Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.m_num * f2.m_num ,f1.m_denom * f2.m_denom);
}
Fraction operator/(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.m_num * f2.m_denom, f1.m_denom * f2.m_num);
}
std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
    out << "Fraction(" << fraction.m_num << "/" << fraction.m_denom << ')';
    return out;
}
std::istream& operator>> (std::istream& in, Fraction& fraction)
{
    in >> fraction.m_num;
    in >> fraction.m_denom;
    fraction.simplify();
    return in;
}
