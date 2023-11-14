#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktNguyenTo(int);
int DemNguyenTo(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran:";
	Xuat(b, k, l);

	int cc;
	cout << "\n\nNhap cot can tinh: ";
	cin >> cc;
	cout << "\n\nSo luong so nguyen to tren cot " << cc << " : " << DemNguyenTo(b, k, l, cc);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
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

bool ktNguyenTo(int n)
{
	if (n < 2)
		return false;
	int dem = 0;
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			dem++;
	return (dem == 2);
}

int DemNguyenTo(int a[][100], int m, int n, int c)
{
	if (m == 0)
		return 0;
	int dem = DemNguyenTo(a, m - 1, n, c); 
	if (ktNguyenTo(a[m - 1][c]))
		dem = dem + 1;
	return dem;
}