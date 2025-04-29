#include"fun.h"
#include<iostream>
using namespace std;
int main()
{
	int n = 0,numA = 0,numB = 0,numC = 0;
	char pur = 'C', start = 'A', medium = 'B';
	cin >> n;
	numA = n;
	cout << "A=" << numA << ' ' << "B=" << numB << ' ' << "C=" << numC << endl;
	hanoi(n, start, medium, pur,numA,numB,numC);
	return 0;
}