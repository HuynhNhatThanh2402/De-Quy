#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void XayDung(float[][100], int, int, float[][100], int&, int&);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);

	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	float c[100][100];
	int t, g;

	XayDung(b, k, l, c, t, g);
	cout << "\nMa tran moi:\n";
	Xuat(c, t, g);
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

void XayDung(float a[][100], int m, int n, float b[][100], int& k, int& l)
{
	if (m == 0)
	{
		k = 0;
		l = n;
		return;
	}
	XayDung(a, m - 1, n, b, k, l);
	for (int j = 0; j < n; j++)
		b[m - 1][j] = abs(a[m - 1][j]);
	k++;
}