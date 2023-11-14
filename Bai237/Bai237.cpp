#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
int ChuSoDau(int);
int DemGiaTri(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);

	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	int cc;
	cout << "\nNhap cot can dem: ";
	cin >> cc;

	cout << "\nSo luong gia tri chan trong ma tran: " << DemGiaTri(b, k, l, cc);
	cout << "\n\n\nKet thuc!!!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "\nNhap m: ";
	cin >> m;
	cout << "\nNhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 201 - 100;
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

int ChuSoDau(int x)
{
	x = abs(x);
	if (x <= 9)
		return x;
	return ChuSoDau(x / 10);
}

int DemGiaTri(int a[][100], int m, int n, int c)
{
	if (m == 0)
		return 0;
	int dem = DemGiaTri(a, m - 1, n, c);
	for (int j = 0; j < n; j++)
		if (ChuSoDau(a[m - 1][j]) % 2 == 0)
			dem++;
	return dem;
}