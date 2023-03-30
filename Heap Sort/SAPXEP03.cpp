#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

void CreateRandArr(int[], int);
void Heapify(int[], int, int);
void BuildHeap(int[], int);
void HeapSort(int[], int);
void Output(int[], int);

int main()
{
	const int n = 50000;
	static int a[n];
	srand(time(NULL));
	CreateRandArr(a, n);
	HeapSort(a, n);
	Output(a, n);
	return 0;
}

void CreateRandArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 4001 - 1000;
}
void Heapify(int a[], int n, int i)
{
	int max = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[max])
		max = l;
	if (r < n && a[r] > a[max])
		max = r;
	if (max != i)
	{
		swap(a[i], a[max]);
		Heapify(a, n, max);
	}
}
void BuildHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
}
void HeapSort(int a[], int n)
{
	BuildHeap(a, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		Heapify(a, i, 0);
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