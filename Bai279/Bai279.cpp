#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void ThemDong(float[][100], int&, int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	int d;
	cout << "\n\nNhap vi tri: ";
	cin >> d;

	ThemDong(b, k, l, d);
	Xuat(b, k, l);
	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> m;
	cout << "Nhap vao so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + rand() / ((float)RAND_MAX / 200);
}

void Xuat(float a[][100], int m, int n)
{
	if (m == 0)
		return;
	Xuat(a, m - 1, n);
	cout << endl;
	for (int j = 0; j < n; j++)
		cout << setw(10) << a[m - 1][j];
}

void ThemDong(float a[][100], int& m, int n, int d)
{
	if (n == 0)
	{
		m++;
		return;
	}
	ThemDong(a, m, n - 1, d);
	for (int i = m;i > d; i--)
		a[i][n - 1] = a[i - 1][n - 1];
	a[d][n - 1] = 1;
}