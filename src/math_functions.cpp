#include "math_functions.h"
#include <iostream>
#include <cmath>

double compute_sqr_root(double number)
{
    if(number < 0)
    {
        std::cout << "Error: Negative input to compute_sqr_root: " << number << std::endl;
    }

    return std::sqrt(number);
}