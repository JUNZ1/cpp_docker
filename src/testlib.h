#pragma once
#include <iostream>
#include <math.h>

double squareRoot(const double a) 
{
    double b = sqrt(a);
    if(b != b) // NaN check
        { return -1.0; }
    else
        { return sqrt(a); }
}
    
class mytestlib
{
    public:
        static void denemeF(){std::cout<<"You DID It!!"<<std::endl;}
};