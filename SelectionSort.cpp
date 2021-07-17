#include<iostream>
#include<cmath>
using namespace std;


void Output(int a[], int n)
{
	cout << "Danh sach phan tu: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void SelectionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		swap(a[i], a[min]);
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
	SelectionSort(a, n);
	cout << "Mang sau khi sx: ";
	Output(a, n);
	return 0;
}