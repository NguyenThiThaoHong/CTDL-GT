#include<iostream>
#define MAX 100
using namespace std;

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] > a[j - 1])
				swap(a[j], a[j + 1]);

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
	BubbleSort(a, n);
	cout << "Mang sau khi sx: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}