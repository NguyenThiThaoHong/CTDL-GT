#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* pNext;
};
typedef struct node NODE;
struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void CreateList(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE* CreateNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		exit(1);
	p->data = x;
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
void Nhap(LIST& L)
{
	int n;
	cout << "\n Nhap so phan tu:  ";
	cin >> n;
	CreateList(L);
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "\nNhap phan tu thu " << i + 1 << " : ";
		cin >> x;
		NODE* p = CreateNode(x);
		if (p != NULL)
			AddHead(L, p);
	}
}
void Xuat(LIST L)
{
	NODE* p = L.pHead;
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
}
void SapXep(LIST& l)
{
	int t;
	for (NODE *p=l.pHead;p!=NULL;p=p->pNext)
		for (NODE *q=p->pNext;q!=NULL;q=q->pNext)
			if (q->data < p->data)
			{
				t = q->data;
				q->data = p->data;
				p->data = t;
			}
}
void GHEP(LIST& l1, LIST& l2)
{
	NODE* p1, * p2;
	LIST l3;
	CreateList(l3);
	int a;
	p1 = l1.pHead;
	while (p1)
	{
		a = p1->data;
		AddHead(l3, CreateNode(a));
		p1 = p1->pNext;
	}
	p2 = l2.pHead;
	while (p2)
	{
		a = p2->data;
		AddHead(l3, CreateNode(a));
		p2 = p2->pNext;
	}
	SapXep(l3);
	Xuat(l3);
}
int main()
{
	int luachon;
	NODE* p;
	LIST l;
	do
	{
		system("cls");

		cout << "DS lua chon: ";
		cout << "\n0.Thoat man hinh.";
		cout << "\n1.Nhap list.";
		cout << "\n2.Xuat list.";
		cout << "\n3.Tao day list 3 tu 2 list khac.";
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 0: break;
		case 1:
		{
			cout << "\nNhap list so nguyen duong: ";
			Nhap(l);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Xuat list: " << endl;
			Xuat(l);
			system("pause");
			break;
		}
		case 3:
		{
			LIST l2;
			CreateList(l2);
			cout << "\nNhap them 1 list moi: ";
			Nhap(l2);
			GHEP(l, l2);
			system("pause");
			break;
		}
		default:cout << "VUI LONG NHAP LUA CHON KHAC";
			break;
		}

	} while (luachon != 0);
	return 0;

}