#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void HoanViDong(float[][100], int, int, int, int);
float TongDong(float[][100], int, int, int);
void SapXep(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran ban dau:";
	Xuat(b, k, l);

	cout << "\n\nMa tran luc sau: ";
	SapXep(b, k, l);
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

void HoanViDong(float a[][100], int m, int n, int d1, int d2)
{
	if (n == 0)
		return;
	HoanViDong(a, m, n - 1, d1, d2);
	swap(a[d1][n - 1], a[d2][n - 1]);
}

float TongDong(float a[][100], int m, int n, int d)
{
	if (n == 0)
		return 0;
	return TongDong(a, m, n - 1, d) + a[d][n - 1];
}

void SapXep(float a[][100], int m, int n)
{
	if (m == 1)
		return;
	for (int i = 0; i <= m - 2; i++)
		if (TongDong(a, m, n, i) > TongDong(a, m, n, m - 1))
			HoanViDong(a, m, n, i, m - 1);
	SapXep(a, m - 1, n);
}