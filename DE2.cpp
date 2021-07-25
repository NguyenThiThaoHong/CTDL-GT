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

void CreateTree(TREE &T)
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
void Input(TREE &T)
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

void Duyet_RNL(TREE T)
{
	//neu cay con phan tu thi duyet
	if (T != NULL)
	{
		Duyet_RNL(T->pRight);//duyet qua trai;
		cout << T->info << " ";//xuat gia tri cua node;
		Duyet_RNL(T->pLeft);//duyet qua phai;
	}
}
int Node_la(TREE T)
{
	if (T == NULL)
		return 0;
	else if (T->pLeft == NULL && T->pRight == NULL)
		return 1;
	return Node_la(T->pLeft) + Node_la(T->pRight);
}
bool SoNguyenTo(int x)
{
	int dem = 0;
	for (int i = 1; i < x; i++)
		if (x % i == 0)
			dem++;
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
			else SearchStandFor(pHuy, T->pRight);
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
		if (SoNguyenTo(T->info) == true)
			XoaNode(T, T->info);
	}
}
void MENU()
{
	cout << "\n0.Thoat man hinh.";
	cout << "\n1.Tao cay nhi phan tim kiem.";
	cout << "\n2.Duyet theo thu tu giam dan.";
	cout << "\n3.Xoa node la so nguyen to.";
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
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\nDuyet cay theo thu tu giam dan: ";
			Duyet_RNL(T);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "\nXoa node la so nguyen to: ";
			XoaNodeSNT(T);
			Duyet_RNL(T);
			system("pause");
			break;
		}
		default:cout << "VUI LONG NHAP LAI LUA CHON";
			break;
		}
	} while (luachon != 0);
	return 0;
}