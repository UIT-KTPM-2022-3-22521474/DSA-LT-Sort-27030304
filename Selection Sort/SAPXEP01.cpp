#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

void CreateRandArr(int[], int);
void SelectionSort(int[], int);
void Output(int[], int);

int main()
{
	const int n = 50000;
	static int a[n];
	srand(time(NULL));
	CreateRandArr(a, n);
	SelectionSort(a, n);
	Output(a, n);
	return 0;
}

void CreateRandArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 4001 - 1000;
}

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[i], a[min]);
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