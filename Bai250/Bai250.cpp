#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float TongDong(float[][100], int, int, int);
float TongLonNhat(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Ma tran ban dau:";
	Xuat(b, k, l);

	cout << "\nTong dong lon nhat trong ma tran: " << TongLonNhat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so hang: ";
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
		cout << setw(8) << setprecision(3) << a[m - 1][j];
}

float TongDong(float a[][100], int m, int n, int d)
{
	if (n == 0)
		return 0;
	float s = TongDong(a, m, n - 1, d);
	s = s + a[d][n - 1];
	return s;
}

float TongLonNhat(float a[][100], int m, int n)
{
	if (m == 1)
		return TongDong(a,m,n,0);
	float lc = TongLonNhat(a, m - 1, n);
	if (TongDong(a, m, n, m - 1) > lc)
		lc = TongDong(a, m, n, m - 1);
	return lc;
}