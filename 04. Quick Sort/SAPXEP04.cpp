#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

void CreateRandArr(int[], int);
void QuickSort(int[], int, int);
void Output(int[], int);

int main()
{
	const int n = 50000;
	static int a[n];
	srand(time(NULL));
	CreateRandArr(a, n);
	QuickSort(a, 0, n - 1);
	Output(a, n);
	return 0;
}

void CreateRandArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 4001 - 1000;
}

void QuickSort(int a[], int l, int r)
{
	if (l >= r) 
		return;
	int pivot = a[(l + r) / 2];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < pivot) 
			i++;
		while (a[j] > pivot) 
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	QuickSort(a, l, j);
	QuickSort(a, i, r);
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