#include<iostream>
#include<cmath>
using namespace std;


void Output(int a[],int n)
{
	cout << "Danh sach phan tu: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";		
}
void InsertionSort(int a[], int n)
{
	int j, i;
	for (i = 1; i < n ; i++)
	{
		int x = a[i];
		for (j = i - 1; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
}
int main()
{
	int a[100];
	int n;

	cout << "Nhap so phan tu mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i << " :";
		cin >> a[i];
	}
	InsertionSort(a, n);
	cout << "Mang sau khi sx: ";
	Output(a, n);
	return 0;
}
