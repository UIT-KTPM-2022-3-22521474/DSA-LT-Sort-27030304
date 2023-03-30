#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

void CreateRandArr(int[], int);
void InsertionSort(int[], int);
void Output(int[], int);

int main()
{
	const int n = 50000;
	static int a[n];
	srand(time(NULL));
	CreateRandArr(a, n);
	InsertionSort(a, n);
	Output(a, n);
	return 0;
}

void CreateRandArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 4001 - 1000;
}

void InsertionSort(int a[], int n)
{
	for (int step = 1; step <= n - 1; step++)
	{
		int n = a[step];
		int pos = 0;
		for (pos = step - 1; pos >= 0 && a[pos] > n; pos--)
			a[pos + 1] = a[pos];
		a[pos + 1] = n;
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 20 == 0)
			cout << endl;
		cout << setw(6) << a[i];
	}
	cout << endl;
}