#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include<cstdint>
#include<iostream>


class FixedPoint{
    std::int_least16_t m_real{};
    std::int_least8_t m_decimal{};
public:
    FixedPoint(int_least16_t real = 0,int_least8_t decimal = 0);

    FixedPoint(double fp=0.00);

    operator double() const{return m_real+static_cast<double>(m_decimal)/100.0;}

    FixedPoint operator-(){
        return{
            static_cast<std::int_least16_t>(-m_real),
            static_cast<std::int_least8_t>(-m_decimal)};
    }


    //comparison operator
    friend bool operator==(const FixedPoint& fp1,const FixedPoint& fp2);

    //Addition
    friend FixedPoint operator+(const FixedPoint& fp1,const FixedPoint& fp2);

    //Substraction
    friend FixedPoint operator-(const FixedPoint& fp1,const FixedPoint& fp2);

    //Division
    friend FixedPoint operator/(const FixedPoint& fp1,const FixedPoint& fp2);

    //Multiplication
    friend FixedPoint operator*(const FixedPoint& fp1,const FixedPoint& fp2);

};

std::istream& operator>>(std::istream& in,FixedPoint& fp);
std::ostream& operator<<(std::ostream& out,const FixedPoint fix);


#endif /*FIXED_POINT_H*/
