#include"FixedPoint.h"
#include<iostream>


void testAddition()
{
    // h/t to reader Sharjeel Safdar for this function
    std::cout << std::boolalpha;
    std::cout << (FixedPoint{ 0.75 } + FixedPoint{ 1.23 } == FixedPoint{ 1.98 }) << '\n'; // both positive, no decimal overflow
    std::cout << (FixedPoint{ 0.75 } + FixedPoint{ 1.50 } == FixedPoint{ 2.25 }) << '\n'; // both positive, with decimal overflow
    std::cout << (FixedPoint{ -0.75 } + FixedPoint{ -1.23 } == FixedPoint{ -1.98 }) << '\n'; // both negative, no decimal overflow
    std::cout << (FixedPoint{ -0.75 } + FixedPoint{ -1.50 } == FixedPoint{ -2.25 }) << '\n'; // both negative, with decimal overflow
    std::cout << (FixedPoint{ 0.75 } + FixedPoint{ -1.23 } == FixedPoint{ -0.48 }) << '\n'; // second negative, no decimal overflow
    std::cout << (FixedPoint{ 0.75 } + FixedPoint{ -1.50 } == FixedPoint{ -0.75 }) << '\n'; // second negative, possible decimal overflow
    std::cout << (FixedPoint{ -0.75 } + FixedPoint{ 1.23 } == FixedPoint{ 0.48 }) << '\n'; // first negative, no decimal overflow
    std::cout << (FixedPoint{ -0.75 } + FixedPoint{ 1.50 } == FixedPoint{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

void testSubstraction(){
    std::cout<<std::boolalpha;
    std::cout<<(FixedPoint{2.00}-FixedPoint{3.89} ==FixedPoint{-1.89})<<'\n';
}

void testDivision(){
    std::cout<<std::boolalpha;
    std::cout<<(FixedPoint{1.0}/FixedPoint{3.0} == FixedPoint{0.33})<<'\n';
}

void testMultiplication(){
    std::cout<<std::boolalpha;
    std::cout<<(FixedPoint{1.99}*FixedPoint{0.99})<<'\n';
}

int main()
{
    testAddition();
    testSubstraction();
    testDivision();
    testMultiplication();
 
    FixedPoint a{ -0.48 };
    std::cout << a << '\n';
 
    std::cout << -a << '\n';
 
    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> a;
    
    std::cout << "You entered: " << a << '\n';

    FixedPoint b{1.3};
    std::cout<<b<<'\n';

    FixedPoint c{1,03};
    std::cout<<c<<'\n';

    //Testing some problems with floating point comparisons

    FixedPoint d = FixedPoint{0.3}*FixedPoint{3.0}+FixedPoint{0.1};
    FixedPoint e = FixedPoint{1.0};
    std::cout<<(d==e)<<'\n';
 
    return 0;
}
