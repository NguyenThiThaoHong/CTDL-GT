#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node* pNext;
};
struct List
{
	Node* pHead;
	Node* pTail;
};

void Init(List&);
int isEmpty(List);
Node* GetNode(int x);
void AddHead(List&, Node*);
void AddTail(List&, Node*);
void InsertAfterQ(List&, Node*, Node*);
void InputHead(List&);
void InputTail(List&);
int RemoveHead(List&);
int RemoveTail(List&);
int RemoveAfterQ(List&, Node*);
int RemoveX(List&, int x);
Node* Search(List, int x);
void RemoveList(List&);
int Count(List);
int InsertX(List&, int&, int&);
void Reverse(List, Node*);
void Output(List);
int Menu();

int main()
{
	List l;
	int option;
	bool flag = true;
	int right;
	while (flag != false)
	{
		option = Menu();
		switch (option)
		{
		case 0:
		{
			cout << "Ket thuc chuong trinh";
			RemoveList(l);
			flag = false;
			break;
		}
		case 1:
		{
			cout << " Nhap danh sach:\n";
			InputHead(l);
			cout << " Xuat danh sach (AddHead): ";
			Output(l);
			break;
		}
		case 2:
		{
			cout << " Nhap danh sach:\n";
			InputTail(l);
			cout << " Xuat danh sach (AddTail): ";
			Output(l);
			break;
		}
		case 3:
		{
			cout << " Danh sach theo chieu cuoi: ";
			Node* r = l.pHead;
			Reverse(l, r);
			cout << endl;
			break;
		}
		case 4:
		{
			cout << " So nut trong danh sach: " << Count(l) << endl;
			break;
		}
		case 5:
		{
			cout << " Nhap du lieu nut can tim: ";
			int x;
			cin >> x;
			Node* q = Search(l, x);
			if (q == NULL)
				cout << " Khong ton tai nut co du lieu tren trong danh sach\n";
			else
			{
				cout << " Nut can tim:\n";
				cout << " info = " << q->info << endl;
				cout << " pNext = " << q->pNext << endl;
			}
			break;
		}
		case 6:
		{
			right = RemoveHead(l);
			if (right != 0)
			{
				cout << " Danh sach sau khi xoa nut dau: ";
				Output(l);
			}
			else
				cout << " Danh sach rong\n";
			break;
		}
		case 7:
		{
			right = RemoveTail(l);
			if (right != 0)
			{
				cout << " Danh sach sau khi xoa nut cuoi: ";
				Output(l);
			}
			else
				cout << " Danh sach rong\n";
			break;
		}
		case 8:
		{
			int x;
			cout << " Nhap du lieu nut can xoa: ";
			cin >> x;
			right = RemoveX(l, x);
			if (right != 0)
			{
				cout << " Danh sach sau khi xoa: ";
				Output(l);
			}
			else
				cout << " Khong ton tai nut co du lieu tren trong danh sach";
			break;
		}
		case 9:
		{
			int x, n;
			cout << " Nhap du lieu nut can chen: ";
			cin >> x;
			cout << " Nhap vi tri can chen: ";
			cin >> n;
			right = InsertX(l, x, n);
			if (right != 0)
			{
				cout << " Danh sach sau khi chen: ";
				Output(l);
			}
			else
				cout << " Vi tri can chen khong dung";
			cout << endl;
			break;
		}
		default:
		{
			cout << " Lua chon khong dung, vui long nhap lai\n";
			cin >> option;
			break;
		}

		}
	}
	return 0;
}

void Init(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
int isEmpty(List l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
Node* GetNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
}
void AddHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void InsertAfterQ(List& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->pNext = q->pNext;
		q->pNext = p;
	}
	else
		AddHead(l, p);
}
void InputHead(List& l)
{
	int n;
	cout << "\n Nhap so phan tu cua danh sach: ";
	cin >> n;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap du lieu nut thu " << i << ": ";
		int x;
		cin >> x;
		Node* p = GetNode(x);
		if (p != NULL)
			AddHead(l, p);
	}
}
void InputTail(List& l)
{
	int n;
	cout << "\n Nhap so phan tu cua danh sach: ";
	cin >> n;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap du lieu nut thu " << i << ": ";
		int x;
		cin >> x;
		Node* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
}
int RemoveHead(List& l)
{
	Node* p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete(p);
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
	return 0;
}
int RemoveTail(List& l)
{
	Node* p = l.pHead;
	if (l.pHead != NULL)
	{
		Node* q = p->pNext;
		while (q->pNext != NULL)
		{
			p = p->pNext;
			q = p->pNext;
		}
		l.pTail = p;
		l.pTail->pNext = NULL;
		delete(q);
		return 1;
	}
	return 0;
}
int RemoveAfterQ(List& l, Node* q)
{
	Node* p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if (p == l.pTail)
				l.pTail = q;
			q->pNext = p->pNext;
			delete(p);
		}
		return 1;
	}
	else
		return 0;
}
int RemoveX(List& l, int x)
{
	Node* p, * q = NULL;
	p = l.pHead;
	while (p != NULL && p->info != x)
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
		RemoveAfterQ(l, q);
	else
		RemoveHead(l);
	return 1;

}
Node* Search(List l, int x)
{
	Node* p;
	p = l.pHead;
	while (p != NULL && p->info != x)
	{
		p = p->pNext;
	}
	if (p == NULL)
		return NULL;
	return p;
}
int Count(List l)
{
	int count = 0;
	Node* p = l.pHead;
	while (p != NULL)
	{
		p = p->pNext;
		count++;
	}
	return count;
}
int InsertX(List& l, int& x, int& n)
{
	if (n == 0)
	{
		Node* q = GetNode(x);
		AddHead(l, q);
		return 1;
	}
	int count = 1;
	Node* p = l.pHead;
	while (p != NULL && count < n)
	{
		p = p->pNext;
		count++;
	}
	if (count < n)
		return 0;
	Node* q = GetNode(x);
	InsertAfterQ(l, q, p);
	return 1;
}
void Reverse(List l, Node* p)
{
	if (p != NULL)
	{
		Reverse(l, p->pNext);
		cout << p->info << " ";
	}
}
void Output(List l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}
void RemoveList(List& l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		Node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete(p);
	}
	l.pTail = NULL;
}

int Menu()
{
	int option;
	cout << "\n ===================================================";
	cout << "\n Vui long chon chuc nang tuong ung";
	cout << "\n 0. Thoat khoi chuong trinh";
	cout << "\n 1. Nhap va xuat danh sach bang cach them vao dau";
	cout << "\n 2. Nhap va xuat danh sach bang cach them vao cuoi";
	cout << "\n 3. In danh sach theo chieu cuoi";
	cout << "\n 4. Dem so nut trong danh sach";
	cout << "\n 5. Tim nut theo du lieu nhap tu ban phim";
	cout << "\n 6. Xoa nut dau danh sach";
	cout << "\n 7. Xoa nut cuoi danh sach";
	cout << "\n 8. Xoa mot nut co du lieu nhap tu ban phim";
	cout << "\n 9. Chen mot nut co du lieu nhap tu ban phim";
	cout << "\n ===================================================";
	cout << "\n Nhap lua chon cua ban: ";
	cin >> option;
	return option;
}