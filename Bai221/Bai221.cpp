#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktChinhPhuong(int);
int TongCot(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran:";
	Xuat(b, k, l);

	int cc;
	cout << "\n\nNhap cot can tinh: ";
	cin >> cc;
	cout << "\n\nTong cac gia tri tren cot " << cc << " : " << TongCot(b, k, l, cc);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 201 - 100;
}

void Xuat(int a[][100], int m, int n)
{
	if (m == 0)
		return;
	Xuat(a, m - 1, n);
	cout << endl;
	for (int j = 0; j < n; j++)
		cout << setw(10) << a[m - 1][j];
}

bool ktChinhPhuong(int n)
{
	if (n < 0)
		return false;
	for (int i = 0; i <= n; i++)
		if (n == i * i)
			return true;
	return false;
}

int TongCot(int a[][100], int m, int n, int c) 
{
	if (m == 0)
		return 0;
	int s = TongCot(a, m - 1, n,c);
	if (ktChinhPhuong(a[m - 1][c]))
		s += a[m - 1][c];	
	return s;
}