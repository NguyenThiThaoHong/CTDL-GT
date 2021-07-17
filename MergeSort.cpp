#include<iostream>
#define MAX 100
using namespace std;



void Merge(int a[], int left, int mid, int right)
{

	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = a[left + i];
	for (j = 0; j < n2; j++)
		R[j] = a[mid + j + 1];
	i = 0; j = 0; k = left;
	while (i < n1 && j < n2)
	{
		a[k++] = (L[i] <= R[i]) ? L[i++] : R[j++];
		 
	}
	while (i < n1)
	{
		a[k++] = L[i++];
	}
	while (j < n2)
	{
		a[k++] = R[j++];
	}
	
}
void MergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}
int main()
{
	int a[MAX];
	int n;

	cout << "Nhap so phan tu mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i+1 << " :";
		cin >> a[i];
	}
	int lenght = n;
	MergeSort(a, 0, lenght-1);
	cout << "Mang sau khi sx: ";
	for (int i = 0; i < lenght; i++)
		cout << a[i] << " ";
	return 0;
}