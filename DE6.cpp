#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void CreateTree(TREE& T)
{
	T = NULL;
}
NODE* Createnode(int x)
{
	NODE* p = new NODE;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
void AddNode(TREE& T, NODE* p)
{
	if (T)
	{
		if (T->info == p->info)
			return;
		if (T->info > p->info)
			AddNode(T->pLeft, p);
		else
			AddNode(T->pRight, p);
	}
	else
		T = p;

}
void Input(TREE& T)
{
	int n, x;
	cout << "\nNhap so luong node: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap node thu " << i + 1 << ":";
		cin >> x;
		NODE* p = Createnode(x);
		AddNode(T, p);
	}

}

void Xuat(TREE T)
{
	
	if (T != NULL)
	{
		Xuat(T->pRight);
		cout << T->info << " ";
		Xuat(T->pLeft);
	}
}
bool KtSoNguyenTo(int x)
{
	int dem = 0;
	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
			dem++;
	}
	if (dem == 2)
		return true;
	return false;
}
void SearchStandFor(TREE& pHuy, TREE& pTM)
{
	if (pHuy->pLeft)
		SearchStandFor(pHuy, pTM->pLeft);
	else
	{
		pHuy->info = pTM->info;
		pHuy = pTM;
		pTM = pTM->pRight;
	}
}
int XoaNode(TREE& T, int x)
{
	if (T)
	{
		if (x < T->info)
			XoaNode(T->pLeft, x);
		if (x > T->info)
			XoaNode(T->pRight, x);
		else
		{
			NODE* pHuy = T;
			if (T->pLeft == NULL)
				T = T->pRight;
			else if (T->pRight == NULL)
				T = T->pLeft;
			else
				SearchStandFor(pHuy, T->pRight);
			delete pHuy;
			return 1;
		}
	}
	else
		return 0;
}
void XoaNodeSNT(TREE& T)
{
	if (T)
	{
		XoaNodeSNT(T->pLeft);
		XoaNodeSNT(T->pRight);
		if (KtSoNguyenTo(T->info) == true)
			XoaNode(T, T->info);
	}
}
int count(node* p)
{
	if (p)
	{
		return 1 + count(p->pLeft) + count(p->pRight);
	}
	else return 0;
}
void DemSoCon(TREE T)
{
	if (T)
	{
		int a = count(T->pLeft);
		int b = count(T->pRight);
		if (a > 0 && a == b)
			cout << T->info;
		DemSoCon(T->pLeft);
		DemSoCon(T->pRight);
	}
}
void MENU()
{
	cout << "\n0.Thoat man hinh.";
	cout << "\n1.Tao va xuat cay nhi phan tim kiem.";
	cout << "\n2.Xoa tat ca cac node la so nguyen to co trong cay tim kiem.";
	cout << "\n3.NODE co cay con trai bang cay con phai.";
}
int main()
{
	TREE T;
	CreateTree(T);
	int x, luachon;
	do {
		system("cls");

		MENU();
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		switch (luachon)
		{
		case 0:break;
		case 1:
		{
			cout << "\nTao cay nhi phan tim kiem: ";
			Input(T);
			cout << "\nXuat cay nhi phan tim kiem: ";
			Xuat(T);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\nXoa cac node trong cay là so nguyen to: ";
			XoaNodeSNT(T);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "\nNode trong cay có cay con trai bang cay con phai: ";
			DemSoCon(T);
			system("pause");
			break;
		}
		default:cout << "VUI LONG NHAP LAI LUA CHON";
			break;
		}
	} while (luachon != 0);
	return 0;
}