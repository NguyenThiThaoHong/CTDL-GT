#include<iostream>
#include<string.h>
using namespace std;

struct date
{
	int ngay;
	int thang;
	int nam;
};
struct hocsinh
{
	char Hoten[80];
	date DATE;
};
typedef struct hocsinh HOCSINH;
struct node
{
	HOCSINH info;
	struct node* pNext;
};
typedef struct node NODEHS;
struct list
{
	NODEHS* Dau;
	NODEHS* Cuoi;
};
typedef struct list LIST;

/*========KHAI BAO HAM==========*/
void CreateList(LIST& L);
NODEHS* CreateHS(HOCSINH x);
void NhapDate(date& d);
void XuatDate(date d);
void NhapHS(HOCSINH& p);
void XuatHS(HOCSINH p);
void Nhap(LIST& L);
void Xuat(LIST L);
void SapXep(LIST& L);
void Remove(LIST& L);
void DS();
int main()
{
	int luachon;
	NODEHS* HS;
	LIST l;
	do
	{
		system("cls");

		cout << "DS lua chon: ";
		DS();
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 0: break;
		case 1:
		{
			cout << "\Nhap danh sach hoc sinh: ";
			Nhap(l);

			cout << "\n=======DANHSACH========" << endl;
			Xuat(l);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\DS sau khi sap xep: ";
			SapXep(l);
			Xuat(l);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "\nHuy danh sach: ";
			Remove(l);
			system("pause");
			break;
		}
		default:cout << "VUI LONG NHAP LUA CHON KHAC";
			break;
		}

	} while (luachon != 0);
	return 0;
	
}

void CreateList(LIST& L)
{
	L.Dau = NULL;
	L.Cuoi = NULL;
}

NODEHS* CreateHS(HOCSINH x)
{
	NODEHS* p = new NODEHS;
	if (p == NULL)
		exit(1);
	p->info = x;
	p->pNext = NULL;
	return p;
}

void NhapDate(date& d)
{
	cout << "\nNhap ngay: ";
	cin >> d.ngay;
	cout << "\nNhap thang: ";
	cin >> d.thang;
	cout << "\nNhap nam: ";
	cin >> d.nam;
}

void XuatDate(date d)
{
	cout << d.ngay << "/" << d.thang << "/" << d.nam;
}

void NhapHS(HOCSINH& p)
{
	cin.ignore();
	cout << "\nNhap ho ten: ";
	cin >> p.Hoten;
	cout << "\nNhap ngay sinh: ";
	NhapDate(p.DATE);
}

void XuatHS(HOCSINH p)
{
	cout << p.Hoten << "|";
	XuatDate(p.DATE);
}
void AddHead(LIST& l, NODEHS* p)
{
	if (l.Dau == NULL)
	{
		l.Dau = p;
		l.Cuoi = l.Dau;
	}
	else
	{
		p->pNext = l.Dau;
		l.Dau= p;
	}
}
void Nhap(LIST& L)
{
	int n;
	cout << "\n Nhap so phan tu cua DS ";
	cin >> n;
	CreateList(L);
	for (int i = 1; i <= n; i++)
	{
		HOCSINH x;
		NhapHS(x);
		NODEHS* p = CreateHS(x);
		if (p != NULL)
			AddHead(L, p);
	}
}

void Xuat(LIST L)
{
	NODEHS* p = L.Dau;
	while (p != NULL)
	{
		XuatHS(p->info);
		p = p->pNext;
		cout << endl;
	}
}

void SapXep(LIST& L)
{
	HOCSINH t;
	for (NODEHS *p=L.Dau;p!=NULL;p=p->pNext)
		for (NODEHS *q=p->pNext;q!=NULL;q=q->pNext)
			if (strcmp(p->info.Hoten, q->info.Hoten) > 0)
			{
				t = p->info;
				p->info = q->info;
				q->info = t;
			}
}

void Remove(LIST& L)
{
	NODEHS* t;
	while (L.Dau!=NULL)
	{
		t = L.Dau;
		L.Dau = t->pNext;
		delete t;

	}
}
void DS()
{
	cout << "\n0.Thoat man hinh.";
	cout << "\n1.Nhap & Xuat danh sach.";
	cout << "\n2.Sap xep danh sach.";
	cout << "\n3.Huy danh sach.";
}
