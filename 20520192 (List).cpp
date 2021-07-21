#include <iostream>
using namespace std;

struct node
{
	int info;
	node* pNext;
};
typedef struct node NODE;

struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;
void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE* KhoitaoNODE(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat ";
		return NULL;
	}
	p->info = x;
	p->pNext = NULL;
	return p;
}
void ThemVaoDau(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void XuatDanhSach(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->info << "  ";
	}
}
int Max(LIST l)
{
	int lc = l.pHead->info;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->info > lc)
			lc = k->info;
	}
	return lc;
}
int Min(LIST l)
{
	int lc = l.pHead->info;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->info < lc)
			lc = k->info;
	}
	return lc;
}
int ktNguyenTo(int n)
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			dem++;
	}
	if (dem == 2)
		return 1;
	return 0;
}
int NguyenToDau(LIST l)
{
	int flag = 0;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (ktNguyenTo(k->info) == 1)
		{
			return k->info;
			flag = 1;
		}
	}
	if (flag == 0)
		return 0;
}
int ktNguyenToMax(LIST l)
{
	int lc = NguyenToDau(l);
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (ktNguyenTo(k->info) == 0 && k->info > lc)
			lc = k->info;
	}
	return lc;
}
int ktChinhPhuong(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (i * i == n)
			return 1;
	}
	return 0;
}
int Tong(LIST l)
{
	int s = 0;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (ktChinhPhuong(k->info) == 1)
			s = s + k->info;
	}
	return s;
}
int main()
{
	NODE* p;
	LIST l;
	int n = 0, luachon;
	Init(l);
	do
	{
		cout << "\n0.Thoat ";
		cout << "\n1.Nhap n so luong ";
		cout << "\n2.Xuat danh sach ";
		cout << "\n3.Tim phan tu lon nhat ";
		cout << "\n4.Tim phan tu nho nhat ";
		cout << "\n5.Tim so nguyen to lon nhat ";
		cout << "\n6.Tong so chinh phuong ";
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 0:break;
		case 1: {
			cout << "Nhap n: ";
			cin >> n;
			for (int i = 0; i <= n; i++)
			{
				int x;
				cout << "\nNhap gia tri cua node: ";
				cin >> x;

				NODE* p = KhoitaoNODE(x);
				ThemVaoDau(l, p);
			}
		}break;
		case 2:
		{
			cout << "\n\nDanh sach lien ket la: \n";
			XuatDanhSach(l);
		}
		case 3:
		{
			cout << "\nPhan tu lon nhat trong danh sach la: " << Max(l);
		}break;
		case 4:
		{
			cout << "\nPhan tu nho nhat trong danh sach la: " << Min(l);
		}break;
		case 5:
		{
			cout << "\nSo nguyen to lon nhat co trong danh sach vua nhap la: " << ktNguyenToMax(l);
		}break;
		case 6:
		{
			cout << "\nTong cac so chinh phuong co trong danh la: " << Tong(l);
		}break;
		default:
			cout << "\nLua chon khong dung. Xin vui long chon lai !";
		}

	} while (luachon != 0);
	return 0;
}