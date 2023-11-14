#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktToanLe(int);
int DemSoLe(int[][100], int, int, int d);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	int d;
	cout << "\n\nNhap dong can tinh: ";
	cin >> d;
	cout << "\n\nSo luong so toan le tren dong " << d << ": " << DemSoLe(b, k, l, d);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> m;
	cout << "Nhap vao so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][100], int m, int n)
{
	if (m == 0)
		return;
	Xuat(a, m - 1, n);
	cout << endl;
	for (int j = 0; j < n; j++)
		cout << setw(10) << a[m - 1][j];
}

bool ktToanLe(int n)
{
	n = abs(n);
	if (n <= 9)
	{
		if (n % 2 != 0)
			return true;
		return false;
	}
	int dv = n % 10;
	if (dv % 2 != 0 && ktToanLe(n / 10))
		return true;
	return false;
}

int DemSoLe(int a[][100], int m, int n, int d)
{
	if (n == 0)
		return 0;
	int dem = DemSoLe(a, m, n - 1, d);
	if (ktToanLe(a[d][n - 1]))
		dem++;
	return dem;
}
