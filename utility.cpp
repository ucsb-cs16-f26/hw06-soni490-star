#include "utility.h"
#include <cmath>

// utility.cpp

// IN THIS FILE, define any of your OWN functions you may need to 
// solve the problems.    


// You will need to include the function prototype in "utility.h" and
// then be sure to  #include "utility.h" in the file where you use
// these functions

double pow(double x, int n){
    double temp = x;
    for (int i=1; i<n; i++)
        temp *= x;
    return temp;
}

bool approxEqual(double a, double b, double tolerance) {
  return fabs(a - b) < tolerance;
}