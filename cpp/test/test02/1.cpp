#include"fun.h"
#include<iostream>
using namespace std;
void move(char start, char pur, int& numa, int& numb, int& numc)
{
	cout << start << ">>" << pur << endl;
	if (start == 'A' && pur == 'C')
	{
		numa--;
		numc++;
	}
	else if (start == 'B' && pur == 'C')
	{
		numb--;
		numc++;
	}
	else if (start == 'B' && pur == 'A')
	{
		numb--;
		numa++;
	}
	else if (start == 'A' && pur == 'B')
	{
		numa--;
		numb++;
	}
	else if (start == 'C' && pur == 'A')
	{
		numc--;
		numa++;
	}
	else if (start == 'C' && pur == 'B')
	{
		numc--;
		numb++;
	}
	cout << "A=" << numa << ' ' << "B=" << numb << ' ' << "C=" << numc << endl;
}
void hanoi(int n, char start, char medium, char pur, int& numa, int& numb, int& numc)
{
	if (n == 1)
	{
		move(start, pur, numa, numb, numc);
	}
	else if (n > 1)
	{
		hanoi(n - 1, start, pur, medium, numa, numb, numc);
		cout << start << ">>" << pur << endl;
		if (start == 'A' && pur == 'C')
		{
			numa--;
			numc++;
		}
		else if (start == 'B' && pur == 'C')
		{
			numb--;
			numc++;
		}
		else if (start == 'B' && pur == 'A')
		{
			numb--;
			numa++;
		}
		else if (start == 'A' && pur == 'B')
		{
			numa--;
			numb++;
		}
		else if (start == 'C' && pur == 'A')
		{
			numc--;
			numa++;
		}
		else if (start == 'C' && pur == 'B')
		{
			numc--;
			numb++;
		}
		cout << "A=" << numa << ' ' << "B=" << numb << ' ' << "C=" << numc << endl;
		hanoi(n - 1, medium, start, pur, numa, numb, numc);

	}
}