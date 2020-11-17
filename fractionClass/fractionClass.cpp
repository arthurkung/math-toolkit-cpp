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
        int absNum{ std::abs(m_num) };
        int absDenom{ std::abs(m_denom) };
        int HCF{ findHCF(std::min(absNum, absDenom),std::max(absNum, absDenom)) };
        m_num /= HCF;
        m_denom /= HCF;
        if (m_denom < 0)
        {
            m_num *= -1;
            m_denom *= -1;
        }
    }
    
}
Fraction& Fraction::operator+=(const Fraction& value)
{
    Fraction sum{ *this + value };
    this->m_num = sum.m_num;
    this->m_denom = sum.m_denom;
    return *this;

}
int Fraction::findHCF(int smallerNum, int largerNum) {

    return (largerNum % smallerNum == 0)?
        smallerNum :
        findHCF(largerNum % smallerNum, smallerNum);
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
