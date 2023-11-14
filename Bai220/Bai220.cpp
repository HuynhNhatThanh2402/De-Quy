#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktDoiXung(int);
int TongDong(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Ma tran ban dau:";
	Xuat(b, k, l);

	int h;
	cout << "\nNhap cot can tinh:";
	cin >> h;

	cout << "\nTong cac so duong: " << TongDong(b, k, l, h);

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

bool ktDoiXung(int k)
{
	k = abs(k);
	int dn = 0;
	for (int t = k; t != 0; t = t / 10)
	{
		int dv = t % 10;
		dn = dn * 10 + dv;
	}
	return (dn == k);
}

int TongDong(int a[][100], int m, int n, int c)
{
	if (m == 0)
		return 0;
	int s = TongDong(a, m-1, n, c);
	if (a[m-1][c]%2!=0)
		s = s + a[m-1][c];
	return s;
}