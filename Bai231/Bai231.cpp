#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int TanSuat(float[][100], int, int, float);

int main()
{
	float b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran:";
	Xuat(b, k, l);

	float e;
	cout << "\n\nNhap x: ";
	cin >> e;
	cout << "\n\nSo lan xuat hien gia tri " << e << ": " << TanSuat(b, k, l, e);

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

int TanSuat(float a[][100], int m, int n, float x)
{
	if (m == 0)
		return 0;
	int dem = TanSuat(a, m - 1, n, x);
	for (int j = 0; j < n; j++)
		if (a[m - 1][j] == x)
			dem++;
	return dem;
}