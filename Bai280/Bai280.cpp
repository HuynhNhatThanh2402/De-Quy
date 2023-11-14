#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void ThemCot(int[][100], int, int&, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Ma tran ban dau:";
	Xuat(b, k, l);

	int h;
	cout << "\nNhap dong can them:";
	cin >> h;

	ThemCot(b, k, l, h);
	cout << "\nMa tran sau khi them:\n";
	Xuat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so hang: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + rand() / ((int)RAND_MAX / 200);
}

void Xuat(int a[][100], int m, int n)
{
	if (m == 0)
		return;
	Xuat(a, m - 1, n);
	cout << endl;
	for (int j = 0; j < n; j++)
		cout << setw(8) << setprecision(3) << a[m - 1][j];
}

void ThemCot(int a[][100], int m, int& n, int c)
{
	if (m == 0)
	{
		n++;
		return;
	}
	ThemCot(a, m - 1, n, c);
	for (int j = n; j > c; j--)
		a[m - 1][j] = a[m - 1][j - 1];
	a[m - 1][c] = 0;
}