#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void LietKe(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	int d;
	cout << "\nNhap vi tri dong: \n";
	cin >> d;

	cout << "\nCac gia tri thoa dieu kien: \n";
	LietKe(b, k, l, d);

	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
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

void LietKe(int a[][100], int m, int n, int dd)
{
	if (n == 0)
		return;
	LietKe(a, m, n - 1, dd);
		if (a[dd][n-1] % 2 == 0)
			cout << setw(10) << a[dd][n-1];
}
