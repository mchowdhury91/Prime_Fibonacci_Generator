// fibonacci_generators.cpp
#include "fibonacci_generators.h"

// iterative fibonacci number generator
bigint iFibonacci(int n) {

	if (n <= 2) return 1;

	bigint n1 = 1, n2 = 1;

	for (int i = 3; i <= n; ++i) {
		bigint temp = n2;
		n2 += n1;
		n1 = temp;
	}

	return n2;
}


bigint iFibonacci(int n, int &operations) {

	if (n <= 2) {
		operations++;
		return 1;
	}
	operations++; // comparison for if

	bigint n1 = 1, n2 = 1;
	operations += 2; // for assigning the 2 variables

	for (int i = 3; i <= n; ++i) {
		operations++; // for comparison in the loop
		bigint temp = n2;
		operations++;
		n2 += n1;
		operations++;
		n1 = temp;
		operations += 2;  // for incrementing after loop and for n1 assignment
	}

	return n2;
}

// helper function for recursive Fibonacci generator
// this uses dynamic programming to store answers
// so we aren't recalculating numbers we already calculating
// specifically, we aren't recalculating f(n-2) twice
// because we calculate it once when calculating f(n-1)
bigint getFibonacci(int n, bigint array[]) {
	if (array[n] > 0) return array[n];   // this means that we already solved this f(n) before

	if (n <= 2) {
		array[n] = 1;
		return array[n];
	}

	if (array[n - 1] > 0) {
		array[n] = array[n - 1] + array[n - 2];
		return array[n];
	}

	array[n] = getFibonacci(n - 1, array) + array[n - 2];
	return array[n];
}

// helper function for recursive Fibonacci generator
// this uses dynamic programming to store answers
// so we aren't recalculating numbers we already calculating
// specifically, we aren't recalculating f(n-2) twice
// because we calculate it once when calculating f(n-1)
bigint getFibonacci(int n, bigint array[], int &operations) {
	if (array[n] > 0) {
		operations++;
		return array[n];
	}
	operations++; // comparison for if

	if (n <= 2) {
		operations++;
		array[n] = 1;
		operations++;
		return array[n];
	}
	operations++; // comparison for if

	array[n] = getFibonacci(n - 1, array) + array[n - 2];
	operations += 2;
	return array[n];
}

bigint getFibonacci_v(int n, std::vector<bigint> &v) {
	if (n <= 2) {
		return 1;
	}

	if (n < v.size()) {
		return v[n];
	}

	if (n - 1 < v.size()) {
		v.push_back(v[n - 1] + v[n - 2]);
		return v[n];
	}

	getFibonacci_v(n - 1, v);
	v.push_back(v[n - 1] + v[n - 2]);
	return v[n];
}

// recursive fibonacci number generator
bigint rFibonacci(int n) {
	if (n <= 2) return 1;

	bigint* array = new bigint[n + 1];
	array[0] = 0;
	array[1] = 1;
	array[2] = 1;
	for (int i = 3; i < n + 1; ++i) {
		array[i] = 0;
	}

	bigint fn = getFibonacci(n, array);
	delete[] array;
	return fn;
}

bigint rFibonacci(int n, int &operations) {
	if (n <= 2) {
		operations++;
		return 1;
	}
	operations++; // comparison in the if

	bigint* array = new bigint[n + 1];
	operations++;

	array[0] = 0;
	array[1] = 1;
	array[2] = 1;

	operations += 3;

	for (int i = 3; i < n + 1; ++i) {
		operations++;
		array[i] = 0;
		operations += 2;
	}

	operations++; //
	return getFibonacci(n, array, operations);
}