#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void XoaDong(float[][100], int&, int, int);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);

	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	int dd;
	cout << "\nNhap dong can xoa: ";
	cin >> dd;

	XoaDong(b, k, l, dd);
	cout << "\nMa tran moi:\n";
	Xuat(b, k, l);
	cout << "\n\n\nKet thuc!!!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "\nNhap m: ";
	cin >> m;
	cout << "\nNhap n: ";
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

void XoaDong(float a[][100], int& m, int n, int d)
{
	if (n == 0)
	{
		m--;
		return;
	}
	XoaDong(a, m, n - 1, d);
	for (int i = d; i <= m - 1; i++)
		a[i][n - 1] = a[i + 1][n - 1];
}