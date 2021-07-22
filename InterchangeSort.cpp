#include<iostream>
#define MAX 100
using namespace std;

void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);

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
	InterchangeSort(a, n);
	cout << "Mang sau khi sx: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}