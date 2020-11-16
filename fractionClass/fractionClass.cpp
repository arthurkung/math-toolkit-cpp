#include <algorithm>
#include <iostream>


class Fraction {
private:
    int m_num;
    int m_denom;
    void simplify() {
        int HCF{findHCF()};
        m_num /= HCF;
        m_denom /= HCF;
        //handle sign here
    }

    int findHCF() {
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
public:
    Fraction(int num=1, int denom = 1):m_num(num), m_denom(denom)
    {
        simplify();
    }
    friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>> (std::istream& in, Fraction& fraction);
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);
    //can we convert to float / int?

};
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

int main()
{/*
    Fraction a{ 1,6 };
    Fraction b{ 1,3 };
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << a + b << "\n";*/

    Fraction c;
    std::cout << "Enter a fraction: \n";
    std::cin >> c;
    std::cout << c << "\n";


    return 0;
}
