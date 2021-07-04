#include <iostream>
using namespace std;
struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;
void Nhap(DIEM&);
void Xuat(DIEM);
int main()
{
	DIEM M;
	Nhap(M);
	cout << "TOA DO DIEM VUA NHAP";
	Xuat(M);
	return 1;

}
void Nhap(DIEM& P)
{
	cout << "Nnhap x : ";
	cin >> P.x;
	cout << "nhap y : ";
	cin >> P.y;

}
void Xuat(DIEM P)
{
	cout << "\n x = " << P.x;
	cout << "\n y = " << P.y;
}