#include<iostream>
#define MAX 100
using namespace std;

void Heap(int a[], int n, int k)
{
	int j;
	j = 2 * k + 1;
	while (j <= n)
	{
		if (j < n)
		{
			if (a[j] < a[j + 1])
				j++;
		}
		if (a[j] <= a[k])
			break;
		else
		{
			swap(a[k], a[j]);
			k = j; 
			j = 2 * k + 1;
		}
	}
}
void CreateHeap(int a[], int n)
{
	int i = (n - 1) / 2;
	while (i >= 0)
	{
		Heap(a, n - 1, i);
		i--;
	}
}
void HeapSort(int a[], int n)
{
	int r;
	r = n - 1;
	CreateHeap(a, n);
	while (r >= 0)
	{
		swap(a[0], a[r]);
		r--;
		if (r > 0)
			Heap(a, r, 0);
	}
}


int main()
{
	int a[MAX];
	int n;
	/*****/
	cout << "Nhap so phan tu mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << " :";
		cin >> a[i];
	}
	HeapSort(a, n);
	cout << "Mang sau khi sx: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}