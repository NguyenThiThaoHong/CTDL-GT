#include<iostream>
#define MAX 100
using namespace std;

void BinaryInsertionSort(int a[], int n)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		x = a[i];
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int m = (left + right) / 2;
			if (x < a[m])
				right = m - 1;
			else
				left = m + 1;
		}
		for (int j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = x;
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
	BinaryInsertionSort(a, n);
	cout << "Mang sau khi sx: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}