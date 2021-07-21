#include<iostream>
#include<string>

using namespace std;
struct sinhvien
{
	string HoTen;
	int MaSo;
	int NamSinh;
	float DiemTB;
};
typedef struct sinhvien SINHVIEN;
struct node
{
	SINHVIEN info;
	struct node* pNext;
};
typedef struct node NODE;
struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Nhap(SINHVIEN&);
void Xuat(SINHVIEN);
void Init(LIST& );
int IsEmpty(LIST );
NODE* GetNode(SINHVIEN);
void AddHead(LIST& , NODE* );
void AddTail(LIST& , NODE* );
void InPutHead(LIST&);
void InPutTail(LIST&);
void OutPut(LIST);
void DiemTB(LIST);
void Remove2000(LIST&);
void DeleteAfterQ(LIST&, NODE *);
void RemoveHead(LIST&);
void Delete(LIST&);


void DS();



void Nhap(SINHVIEN& x)
{
	cout << "Nhap ho va ten sinh vien: ";
	cin >> x.HoTen;
	cout << "\nNhap ma so :";
	cin >> x.MaSo;
	cout << "\n Nhap nam sinh :";
	cin >> x.NamSinh;
	cout << "\n Diem TB: ";
	cin >> x.DiemTB;
}

void Xuat(SINHVIEN x)
{
	cout << "\n thong tin SV " << x.HoTen << "|" << x.MaSo << "|" << x.NamSinh << "|" << x.DiemTB;
}

void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

int IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
NODE* GetNode(SINHVIEN x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddHead(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void InPutHead(LIST& l)
{
	int n;
	cout << "\n Nhap so phan tu cua DS ";
	cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		SINHVIEN x;
		Nhap(x);
		NODE* p = GetNode(x);
		if (p != NULL)
			AddHead(l, p);
	}
}
void InPutTail(LIST& l)
{
	int n;
	cout << "\nNhap so phan tu cua DS ";
	cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		SINHVIEN x;
		Nhap(x);
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
}
void OutPut(LIST l)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		Xuat(p->info);
		p = p->pNext;
	}
}

void DiemTB(LIST l )
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		if (p->info.DiemTB < 5)
			Xuat(p->info);
		p = p->pNext;
	}
}

void DeleteAfterQ(LIST& l, NODE* q)
{
	NODE* p;
	if (q != NULL)
	{
		p = q->pNext; 
		if (p != NULL) 
		{
			if (p == l.pTail) 
				l.pTail = q;
			q->pNext = p->pNext;
			p = NULL;
			delete p;
		}
	}
}

void RemoveHead(LIST& l)
{
	NODE* p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		p = NULL;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
}

void Remove2000(LIST& l )
{
	if (l.pHead == NULL)
		return;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		if (p->info.NamSinh < 2000)
		{
			if (p == l.pHead)
				RemoveHead(l);
			else
			{
				NODE* q = l.pHead;
				while (q->pNext != p)
					q = q->pNext;
				DeleteAfterQ(l,q);
			}
		}
		p = p->pNext;
	}
}


void SapXep(LIST& l)
{
	NODE* p = l.pHead;
	if (p != NULL)
	{
		NODE* q = p->pNext;
		if (p->info.DiemTB < p->info.DiemTB)
		{
			SINHVIEN temp = p->info;
			p->info = q->info;
			q->info = temp;
		}
		q = q->pNext;
	}
	p = p->pNext;
}
void Delete(LIST& l)
{
	if (l.pHead == NULL)
		return;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		Xuat(p->info);
		RemoveHead(l);
		p = p->pNext;
	}
}

int main()
{
	SINHVIEN a, b;
	LIST l;

	int luachon;
	do
	{
		cout << "\n dach sch lua chon la :";
		DS();
		cout << "\n Nhap lua chon: ";
		cin >> luachon;

		switch (luachon)
		{
		case 0:break;
		case 1:
		{
			cout << "\n DS sinh vien them vao dau la : ";
			InPutHead(l);

			cout << "\n Ds sinh vien vua nhap la: ";
			OutPut(l);
			break;
		}
		case 2:
		{
			cout << "\nDS sinh vien them vao cuoi la: ";
			InPutTail(l);

			cout << "\nDS sinh vien vua nhap la:";
			OutPut(l);
			break;
		}
		case 3:
		{
			cout << "\n DS sinh vien :";
			InPutHead(l);

			cout << "\nDanh sach sinh vien co DiemTB nho hon 5 la: ";
			DiemTB(l);
			break;
		}
		case 4:
		{
			cout << "DS sinh vien: ";
			InPutHead(l);

			Remove2000(l);
			cout << "Ds sinh vien con lai sau khi xoa ";
			OutPut(l);
			break;
		}
		case 5:
		{
			cout << "\nDS sinh vien: ";
			InPutHead(l);

			SapXep(l);
			cout << "\nDanh sach sau khi sap xep tang dan theo diem TB ";
			OutPut(l);
			break;

		}
		case 6:
		{
			cout << "\n DS sinh vien: ";
			InPutHead(l);

			Delete(l);
			cout << "Xoa tat ca danh sach sinh vien voi yeu cau truoc khi xoa in ra thong tin sinh vien bi xoa khoi danh sach ";
			OutPut(l);
			break;

		}
		default: cout << "\n moi ban nhap lai gia tri khac trong danh sach ";
			break;
		}
	} while (luachon != 0);
	return 0;

}

void DS()
{
	cout << "\n ========================" << endl;
	cout << "0.Thoat khoi chuong trinh" << endl;
	cout << "1.Nhap va Xuat DS sinh vien tu ban phim bang thao tac them vao dau " << endl;
	cout << "2.Nhap va Xuat DS sinh vien tu ban phim bang thao tac them vao cuoi " << endl;
	cout << "3.In ra DS sinh vien co diem TB lon hon 5" << endl;
	cout << "4.Xoa sinh vien cos nam sinh truoc 2000" << endl;
	cout << "5.Sap xep SV theo thu tu tang dan cua Diem TB " << endl;
	cout << "6.Xoa tat ca DSSV  yeu cau khi xoa in ra thong tin SV " << endl;
	cout << "========================" << endl;
}