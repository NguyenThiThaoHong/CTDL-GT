#include<iostream>
#define MAX 100
using namespace std;

void ShakerSort(int a[], int n)
{
	int j, left, right, k;
	left = 0; right = n - 1; k = n - 1;
	while (left < right)
	{
		for (j=right;j>left;j--)
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				k = j;
			}
		left = k;
		for (j=left;j<right;j++)
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				k = j;
			}
		right = k;
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
	ShakerSort(a, n);
	cout << "Mang sau khi sx: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}