#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void SapDongGiam(float[][100], int, int, int);

int main()
{
	float b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran ban dau:";
	Xuat(b, k, l);

	int dd;
	cout << "\n\nDong can sap xep: ";
	cin >> dd;
	cout << "\n\nMa tran luc sau: ";
	SapDongGiam(b, k, l, dd);
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

void SapDongGiam(float a[][100], int m, int n, int d)
{
	if (n == 1)
		return;
	for (int j = 0; j <= n - 2; j++)
		if (a[d][j] < a[d][n - 1])
			swap(a[d][j], a[d][n - 1]);
	SapDongGiam(a, m, n - 1, d);
}