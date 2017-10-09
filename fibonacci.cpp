#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include "fibonacci_generators.h"

using namespace std;
using namespace std::chrono;    // used to measure execution time of quicksort function

bool fexists(string filename) {
	ifstream ifile(filename);
	return (bool)ifile;
}


bool isPrime(bigint n) {
	if (n == 2) {
		// 2 is a prime
		return true;
	}

	if (n == 1 || n % 2 == 0) {
		// 1 is not a prime and even numbers are not prime
		return false;
	}

	// I use the following segment to output progress
	// when checking on prime Fibonacci numbers bigger
	// than 2,970,000
	// I can't do bigint x = 2970000 because that is too big a number 
	// for the compiler
	bigint x = 297 * 10000;
	x = x * 1000;
	if(n > x)
	 cout << "determining if " << n << " is prime..." << endl;

	bigint sqrtN = sqrt(n);

	for (bigint i = 3; i <= sqrtN; i += 2) {
		// if we reached this point, our number is odd
		// odd numbers are not divisible by even numbers
		// so we only check for odd divisors (odd i's)
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

/**
bool isPrime(bigint n) {
	if (n == 2 || n == 3) {
		return true;
	}

	if (n == 1 || (n % 2) == 0) {
		return false;
	}

	bigint halfN = n / 2;

	for (bigint i = 3; (i*i) < halfN; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
**/


string generateFileName(int fileNum, string fileName, string extension) {
	if (extension[0] != '.') {
		extension.insert(0, 1, '.');
	}
	string filePrefix = fileName;
	fileName.append(to_string(fileNum));
	fileName.append(extension);

	while (fexists(fileName)) {
		fileNum++;
		fileName = filePrefix;
		fileName.append(to_string(fileNum));
		fileName.append(extension);
	}

	return fileName;
}

/**

int main(int argc, char** argv) {

	high_resolution_clock::time_point t1, t2;
	bigint target = 1000000;
	int n = 1;
	bigint x = 0;
	t1 = high_resolution_clock::now();
	while (x <= target) {
		n++;
		x = iFibonacci(n);
	}
	t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1).count();

	n = 1;
	x = 0;
	t1 = high_resolution_clock::now();
	while (x <= target) {
		n++;
		x = rFibonacci(n);
	}
	t2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(t2 - t1).count();

	cout << "The first Fibonacci number greater than " << target << " is " << x;
	cout << ", which is f" << n << endl;

	cout << "Iterative calculation time: " << duration << endl;
	cout << "Recursive calculation time: " << duration2 << endl;
	cout << "f" << (n - 1) << " is " << iFibonacci(n - 1) << endl;
	cout << "f" << (n - 2) << " is " << iFibonacci(n - 2) << endl << endl;

	x = 0;
	n = 1;
	target = 1000000000;

	t1 = high_resolution_clock::now();
	while (x <= target) {
		n++;
		x = iFibonacci(n);
	}
	t2 = high_resolution_clock::now();
	duration = duration_cast<microseconds>(t2 - t1).count();

	n = 1;
	x = 0;
	t1 = high_resolution_clock::now();
	while (x <= target) {
		n++;
		x = rFibonacci(n);
	}
	t2 = high_resolution_clock::now();
	duration2 = duration_cast<microseconds>(t2 - t1).count();

	cout << "The first Fibonacci number greater than " << target << " is " << x;
	cout << ", which is f" << n << endl;

	cout << "Iterative calculation time: " << duration << endl;
	cout << "Recursive calculation time: " << duration2 << endl;
	cout << "f" << (n - 1) << " is " << iFibonacci(n - 1) << endl;
	cout << "f" << (n - 2) << " is " << iFibonacci(n - 2) << endl << endl;

	system("PAUSE");
	return 0;
}**/




int main(int argc, char** argv) {

	int operations = 0;
	high_resolution_clock::time_point t1, t2;

	vector<bigint> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);

	string filename = "primes.txt";
	ofstream primes;

	primes.open(filename, ios_base::app);
	int primecount = 0;
	int n = 1;
	
	//int primecount = 12;
	//int n = 101;
	bigint x = 0;
	t1 = high_resolution_clock::now();
	while (primecount < 200) {
		if (isPrime(n) || n == 4) {
			x = getFibonacci_v(n, v);
			string numth[10] = { "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th" };
			if (n > 47) {
				cout << "checking f(" << n << ")...";
			}
			if (isPrime(x)) {
				int nextCount = primecount + 1;
				t2 = high_resolution_clock::now();
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				if (nextCount >= 11 && nextCount <= 20) {
					cout << "Time to calculate " << (primecount + 1) << "th prime Fibonacci is " << duration << endl;
				}
				else {
					cout << "Time to calculate " << (primecount + 1) << numth[(primecount + 1) % 10] << " prime Fibonacci is " << duration << endl;
				}

				primecount++;
				cout << "f(" << n << ") = " << x << endl;
				primes << x << "\n";
				t1 = high_resolution_clock::now();
			}
		}
		n++;
	}
	cout << n << endl;

	/**
	int fileNum = 0;
	string fileName;
	ofstream iTimeData;
	ofstream rTimeData;

	fileNum = 0;
	fileName = generateFileName(fileNum, "RecursiveFibonacciData", ".txt");
	int n = 1000;
	rTimeData.open(fileName, ios_base::app);

	for (int i = 0; i < 20; ++i) {
		operations = 0;
		t1 = high_resolution_clock::now();
		cout << "f" << n << " is: ";
		cout << rFibonacci(n) << endl;
		t2 = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(t2 - t1).count();

		cout << "\nCalculation time recursively: " << duration << " microseconds\n";
		//cout << "Operations for recursive function: " << operations << endl;
		cout << endl;
		rTimeData << duration << "\n";
	}



	fileName = generateFileName(fileNum, "IterativeFibonacciData", ".txt");

	iTimeData.open(fileName, ios_base::app);

	for (int i = 0; i < 20; ++i) {
		operations = 0;
		t1 = high_resolution_clock::now();
		cout << "f" << n << " is: ";
		cout << iFibonacci(n) << endl;
		t2 = high_resolution_clock::now();

		auto duration = duration_cast<microseconds>(t2 - t1).count();

		cout << "\nCalculation time iteratively: " << duration << " microseconds\n";
		//cout << "Operations for iterative function: " << operations << endl;
		cout << endl;
		iTimeData << duration << "\n";
	}
	
	iTimeData.close();
	rTimeData.close();

	/**
	int fileNum = 0;

	cout << "Sorting time: " << duration << " microseconds\n\n";
	ofstream timeData;

	string fileName = "RecursiveFibonacciTimes";
	string filePrefix = fileName;

	fileName.append(to_string(fileNum));
	fileName.append(".txt");
	while(fexists(fileName)){
	fileNum++;
	fileName = filePrefix;
	fileName.append(to_string(fileNum));
	fileName.append(".txt");
	}
	timeData.open(fileName, ios_base::app);
	timeData << duration << "\n";
	**/


	system("PAUSE");
	return 0;
}


