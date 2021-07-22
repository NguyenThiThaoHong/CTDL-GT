#include<iostream>
#define MAX 100
using namespace std;
void QuickSort1(int a[], int left, int right)
{
	int x = a[right];
	int i = left - 1, j = right;
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
		QuickSort1(a, left, j);

	if (i < right)
		QuickSort1(a, i, right);
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
	QuickSort1(a, 0, lenght - 1);
	cout << "Mang sau khi sx: ";
	for (int i = 0; i < lenght; i++)
		cout << a[i] << " ";
	return 0;
}