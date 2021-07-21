#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MAX 100
using namespace std;
int Menu();
void input(int*, int&);
void output(int*, int);
int Max(int*, int);
void AllMax(int*, int);
int TimKiemTuyenTinh(int*, int, int);
int TimKiemTuyenTinhCaiTien(int*, int, int);
void SearchAll(int*, int, int);
int TimKiemNhiPhan(int*, int&, int&);
int TimKiemNoiSuy(int*, int&, int&);
void InterchangeSort(int*, int);
void SelectionSort(int*, int);
void CapGiaTri(int*, int);

int main()
{
	int a[MAX];
	int b[MAX];
	int na;
	int nb;
	int x;
	bool flag = true;
	int option;
	input(a, na);
	while (flag != false)
	{
		option = Menu();
		switch (option)
		{
		case 0:
		{
			cout << "\n Ket thuc chuong trinh.";
			flag = false;
			break;
		}
		case 1:
		{
			cout << "\n In mang: ";
			output(a, na);
			break;
		}
		case 2:
		{
			int imax = Max(a, na);
			cout << "\n Gia tri lon nhat trong mang: " << a[imax] << endl;
			break;
		}
		case 3:
		{
			int imax = Max(a, na);
			cout << "\n Vi tri co gia tri lon nhat trong mang: " << imax << endl;
			break;
		}
		case 4:
		{
			cout << "\n Toan bo cac vi tri chua gia tri lon nhat: ";
			AllMax(a, na);
			cout << endl;
			break;
		}
		case 5:
		{
			clock_t start, end;
			cout << "\n Nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			int vitri = TimKiemTuyenTinh(a, na, x);
			end = clock();
			if (vitri != -1)
				cout << "\n Vi tri cua gia tri " << x << " trong mang: " << vitri << endl;
			else
				cout << "\n Mang khong co gia tri " << x << endl;
			double time = (double)((end - start) / CLOCKS_PER_SEC);
			cout << "\n Thoi gian thuc hien thuat toan: " << time << endl;
			break;
		}
		case 6:
		{
			clock_t start, end;
			cout << "\n Nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			int vitri = TimKiemTuyenTinhCaiTien(a, na, x);
			end = clock();
			if (vitri != -1)
				cout << "\n Vi tri cua gia tri " << x << " trong mang: " << vitri << endl;
			else
				cout << "\n Mang khong co gia tri " << x << endl;
			double time = (double)((end - start) / CLOCKS_PER_SEC);
			cout << "\n Thoi gian thuc hien thuat toan: " << time << endl;
			break;
		}
		case 7:
		{
			cout << "\n Nhap gia tri can tim: ";
			cin >> x;
			SearchAll(a, na, x);
		}
		case 8:
		{
			cout << "\n Nhap so luong phan tu trong mang: ";
			cin >> nb;
			srand(time(NULL));
			b[0] = rand() % 100;
			for (int i = 1; i < nb; i++)
				b[i] = b[i - 1] + rand() % 100 + 1;
			cout << "\n Mang vua tao: ";
			output(b, nb);
			cout << "\n Nhap gia tri can tim: ";
			cin >> x;
			clock_t start, end;
			start = clock();
			int vitri = TimKiemNhiPhan(b, nb, x);
			end = clock();
			if (vitri != -1)
				cout << "\n Vi tri cua gia tri " << x << " trong mang: " << vitri << " ";
			else
				cout << "\n Mang khong co gia tri " << x << endl;
			double time = (double)((end - start) / CLOCKS_PER_SEC);
			cout << "\n Thoi gian thuc hien thuat toan: " << time << endl;
			break;
		}
		case 9:
		{
			cout << "\n Nhap so luong phan tu trong mang: ";
			cin >> nb;
			srand(time(NULL));
			b[0] = rand() % 100;
			for (int i = 1; i < nb; i++)
				b[i] = b[i - 1] + rand() % 100 + 1;
			cout << "\n Mang vua tao: ";
			output(b, nb);
			cout << "\n Nhap gia tri can tim: ";
			cin >> x;
			clock_t start, end;
			start = clock();
			int vitri = TimKiemNoiSuy(b, nb, x);
			end = clock();
			if (vitri != -1)
				cout << "\n Vi tri cua gia tri " << x << " trong mang: " << vitri << " ";
			else
				cout << "\n Mang khong co gia tri " << x << endl;
			double time = (double)((end - start) / CLOCKS_PER_SEC);
			cout << "\n Thoi gian thuc hien thuat toan: " << time << endl;
			break;
		}
		case 10:
		{
			cout << "\n Cac cap gia tri trong mang: ";
			CapGiaTri(a, na);
			cout << endl;
			break;
		}
		case 11:
		{
			clock_t start, end;
			start = clock();
			InterchangeSort(a, na);
			end = clock();
			cout << "\n Mang sau khi sap xep: ";
			output(a, na);
			double time = (double)((end - start) / CLOCKS_PER_SEC);
			cout << "\n Thoi gian thuc hien thuat toan: " << time << endl;
			break;
		}
		case 12:
		{
			clock_t start, end;
			start = clock();
			SelectionSort(a, na);
			end = clock();
			cout << "\n Mang sau khi sap xep: ";
			output(a, na);
			double time = (double)((end - start) / CLOCKS_PER_SEC);
			cout << "\n Thoi gian thuc hien thuat toan: " << time << endl;
			break;
		}
		default:
		{
			cout << "\n Lua chon khong dung, xin moi nhap lai.";
			break;
		}
		}
	}
	return 0;
}

int Menu()
{
	int option;
	cout << "\n Chon chuc nang tuong ung";
	cout << "\n 1.  In cac phan tu mang";
	cout << "\n 2.  Tim gia tri lon nhat trong mang";
	cout << "\n 3.  Tim vi tri chua gia tri lon nhat trong mang";
	cout << "\n 4.  Tim tat ca vi tri chua gia tri lon nhat";
	cout << "\n 5.  Tim vi tri chua x bang tim kiem tuyen tinh";
	cout << "\n 6.  Tim vi tri chua x bang tim kiem tuyen tinh cai tien";
	cout << "\n 7.  Tim tat ca vi tri chua x";
	cout << "\n 8.  Phat sinh mang tang dan va tim vi tri chua x bang tim kiem nhi phan";
	cout << "\n 9.  Phat sinh mang tang dan va tim vi tri chua x bang tim kiem noi suy";
	cout << "\n 10. Liet ke tat ca cap gia tri trong mang";
	cout << "\n 11. Sap xep mang ban dau bang cach doi cho truc tiep";
	cout << "\n 12. Sap xep mang ban dau bang cach chon truc tiep";
	cout << "\n 13.  Thoat chuong trinh";
	cout << "\n Lua chon cua ban: ";
	cin >> option;
	return option;
}

void input(int* a, int& n)
{
	cout << "\n Nhap so luong phan tu trong mang: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}
void output(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int Max(int* a, int n)
{
	int imax = 0;
	int max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max)
		{
			max = a[i];
			imax = i;
		}
	return imax;
}
void AllMax(int* a, int n)
{
	int imax = Max(a, n);
	for (int i = 0; i < n; i++)
		if (a[i] == a[imax])
			cout << i << " ";
}
int TimKiemTuyenTinh(int* a, int n, int x)
{
	int i = 0;
	while (i < n)
	{
		if (a[i] == x)
			return i;
		i++;
	}
	return -1;
}
int TimKiemTuyenTinhCaiTien(int* a, int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	if (i < n) return i;
	return -1;
}
int TimKiemNhiPhan(int* a, int& n, int& x)
{
	int l = 0, r = n - 1;
	int m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (a[m] == x) return m;
		else if (a[m] < x)
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}
int TimKiemNoiSuy(int* a, int& n, int& x)
{
	int l = 0, r = n - 1;
	int m;
	while (l <= r)
	{
		m = l + (r - l) * (x - a[l]) / (a[r] - a[l]);
		if (a[m] == x) return m;
		else if (a[m] < x)
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}
void SearchAll(int* a, int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			dem++;
			if (dem == 1)
				cout << "\n Vi tri cua gia tri " << x << " trong mang: ";
			cout << i << " ";
		}
	}
	if (dem == 0) cout << "\n Khong co gia tri " << x << " trong mang";
	cout << endl;

}
void InterchangeSort(int* a, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void SelectionSort(int* a, int n)
{
	int min, temp;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min]) min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
void CapGiaTri(int* a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			cout << "(" << a[i] << ", " << a[j] << ") ";
		}
}