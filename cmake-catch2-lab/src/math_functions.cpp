#include "math_functions.h"
#include <cmath>

double compute_sqr_root(double number)
{
    if(number < 0)
    {
        return -1;
    }
    return std::sqrt(number);
}