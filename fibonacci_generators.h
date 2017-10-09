//fibonacci_generators.h file
#ifndef _fibonacci_generators_h
#define _fibonacci_generators_h

#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

typedef boost::multiprecision::int1024_t bigint;

// iterative fibonacci number generator
bigint iFibonacci(int n);

bigint iFibonacci(int n, int &operations);

// helper function for recursive Fibonacci generator
// this uses dynamic programming to store answers
// so we aren't recalculating numbers we already calculating
// specifically, we aren't recalculating f(n-2) twice
// because we calculate it once when calculating f(n-1)
bigint getFibonacci(int n, bigint array[]);

// helper function for recursive Fibonacci generator
// this uses dynamic programming to store answers
// so we aren't recalculating numbers we already calculating
// specifically, we aren't recalculating f(n-2) twice
// because we calculate it once when calculating f(n-1)
bigint getFibonacci(int n, bigint array[], int &operations);

//Precondition: v must be a vector with the initial values of atleast {0, 1, 1} populated
bigint getFibonacci_v(int n, std::vector<bigint> &v);
// recursive fibonacci number generator
bigint rFibonacci(int n);
bigint rFibonacci(int n, int &operations);

#endif