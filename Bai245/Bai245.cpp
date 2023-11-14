#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
int AmLonNhat(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Ma tran ban dau:";
	Xuat(b, k, l);

	if (AmLonNhat(b, k, l) == 0)
		cout << "\nMa tran khong co so am";
	else
		cout << "\nSo am lon nhat trong ma tran: " << AmLonNhat(b, k, l);

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

int AmLonNhat(int a[][100], int m, int n)
{
	if (m == 0)
		return 0;
	int lc = AmLonNhat(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (a[m - 1][j]<lc)
			lc=a[m-1][j];
	return lc;
}