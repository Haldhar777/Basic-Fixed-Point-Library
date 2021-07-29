#include"FixedPoint.h"
#include<iostream>
#include<cstdint>
#include<cmath>


FixedPoint::FixedPoint(std::int_least16_t real,std::int_least8_t decimal):m_real{real},m_decimal{m_decimal}{

    if(m_real<0||m_decimal<0){
        if(m_real>0)
            m_real=-m_real;
        if(m_decimal>0)
            m_decimal = -m_decimal;
    }
}

FixedPoint::FixedPoint(double fp){
    m_real = static_cast<std::int_least16_t>(fp);

    m_decimal = static_cast<std::int_least8_t>(std::round(fp*100 - m_real*100));
}

bool operator==(const FixedPoint& fp1,const FixedPoint& fp2){
    return(fp1.m_real == fp2.m_real&&fp1.m_decimal==fp2.m_decimal);
 }

FixedPoint operator+(const FixedPoint& fp1,const FixedPoint& fp2){
    return{static_cast<double>(fp1)+static_cast<double>(fp2)};
}

FixedPoint operator-(const FixedPoint& fp1,const FixedPoint& fp2){
    return{static_cast<double>(fp1)-static_cast<double>(fp2)};
}

FixedPoint operator/(const FixedPoint& fp1,const FixedPoint& fp2){
    return{static_cast<double>(fp1)/static_cast<double>(fp2)};
}

FixedPoint operator*(const FixedPoint& fp1,const FixedPoint& fp2){
    return{static_cast<double>(fp1)*static_cast<double>(fp2)};
}

std::istream& operator>>(std::istream& in,FixedPoint& fp){
    double value{};
    in>>value;
    fp = value;
    return in;
}

std::ostream& operator<<(std::ostream& out,const FixedPoint fix){
    out<<static_cast<double>(fix);
    return out;
}



