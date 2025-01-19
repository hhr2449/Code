#include"fun.h"
using namespace std;
int main()
{
	int n = 0,numa = 0,numb = 0,numc = 0;
	char pur = 'C', start = 'A', medium = 'B';
	cin >> n;
	numa = n;
	cout << "A=" << numa << ' ' << "B=" << numb << ' ' << "C=" << numc << endl;
	hanoi(n, start, medium, pur,numa,numb,numc);
	return 0;
}