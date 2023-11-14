#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void DongTang(int[][100], int, int, int);
void DongGiam(int[][100], int, int, int);
void SapXep(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	cout << "\n\n\nMang sau khi sap xep: ";
	SapXep(b, k, l);
	Xuat(b, k, l);
	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> m;
	cout << "Nhap vao so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
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

void DongTang(int a[][100], int m, int n, int d)
{
	if (n == 1)
		return;
	for (int j = 0;j <= n - 2;j++)
		if (a[d][j] > a[d][n - 1])
			swap(a[d][j], a[d][n - 1]);
	DongTang(a, m, n - 1, d);
}

void DongGiam(int a[][100], int m, int n, int d)
{
	if (n == 1)
		return;
	for (int j = 0;j <= n - 2;j++)
		if (a[d][j] < a[d][n - 1])
			swap(a[d][j], a[d][n - 1]);
	DongGiam(a, m, n - 1, d);
}
//Da sua
void SapXep(int a[][100], int m, int n)
{
	if (m == 1)
		return;
	SapXep(a, m - 1, n);
	if ((m - 1) % 2 == 0)
		DongTang(a, m, n, m - 1);
	else
		DongGiam(a, m, n, m - 1);
}