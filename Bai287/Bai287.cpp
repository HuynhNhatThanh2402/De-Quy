#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void DichXuongCot(float[][100], int, int, int);
void DichXuong(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	DichXuong(b, k, l);

	cout << "\nMa tran luc sau:\n";
	Xuat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
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
		cout << setw(10) << setprecision(3) << a[m - 1][j];
}

void DichXuongCot(float a[][100], int m, int n, int cc)
{
	float temp = a[m - 1][cc];
	for (int i = m - 1; i >= 1; i--)
		a[i][cc] = a[i - 1][cc];
	a[0][cc] = temp;
}

void DichXuong(float a[][100], int m, int n)
{
	if (n == 0)
		return;
	DichXuong(a, m, n - 1);
	DichXuongCot(a, m, n, n - 1);
}