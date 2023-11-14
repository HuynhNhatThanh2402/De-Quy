#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float LonNhatCot(float[][100], int, int, int);
void ThemDong(float[][100], int&, int);

int main()
{
	float b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran ban dau:";
	Xuat(b, k, l);

	cout << "\n\nMa tran luc sau: ";
	ThemDong(b, k, l);
	Xuat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
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
		cout << fixed << setprecision(3) << setw(10) << a[m - 1][j];
}

float LonNhatCot(float a[][100], int m, int n, int c)
{
	if (m == 1)
		return a[0][c];
	float lc = LonNhatCot(a, m - 1, n, c);
	if (a[m - 1][c] > lc)
		lc = a[m - 1][c];
	return lc;
}

void ThemDong(float a[][100], int& m, int n)
{
	if (n == 0)
	{
		m++;
		return;
	}
	ThemDong(a, m, n - 1);
	a[m - 1][n - 1] = LonNhatCot(a, m - 1, n, n - 1);
}