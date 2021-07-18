#include<iostream>
#define MAX 100
using namespace std;

void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left; int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
			
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
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
	int lenght = n;
	QuickSort(a, 0, lenght - 1);
	cout << "Mang sau khi sx: ";
	for (int i = 0; i < lenght; i++)
		cout << a[i] << " ";
	return 0;
}