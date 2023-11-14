#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int DemChuSo(int);
int DemChuSo(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	cout << "\n\nSo luong chu so trong ma tran: " << DemChuSo(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
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

int DemChuSo(int n)
{
	n = abs(n);
	if (n <= 9)
		return 1;
	return DemChuSo(n / 10) + 1;
}

int DemChuSo(int a[][100], int m, int n)
{
	if (m == 0)
		return 0;

	int s = DemChuSo(a, m - 1, n);
	for (int j = 0; j < n; j++)
		s += DemChuSo(a[m - 1][j]);
	return s;
}
