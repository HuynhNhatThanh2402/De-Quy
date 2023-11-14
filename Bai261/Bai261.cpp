#include <iostream>
#include <cstdlib> 
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

bool ktDong1(float[][100], int, int, int);
bool ktDong2(float[][100], int, int, int);
bool ktDong3(float[][100], int, int, int);
void LietKe(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:";
	Xuat(b, k, l);

	cout << "\n\nCac dong thoa dieu kien la: ";
	LietKe(b, k, l);

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
		cout << fixed << setw(10) << setprecision(3) << a[m - 1][j];
}

bool ktDong1(float a[][100], int m, int n, int d)
{
	if (n == 0)
		return 0;
	if (a[d][n - 1] > 0)
		return true;
	return ktDong1(a, m, n - 1, d);
}

bool ktDong2(float a[][100], int m, int n, int d)
{
	if (n == 0)
		return 0;
	if (a[d][n - 1] == 0)
		return true;
	return ktDong2(a, m, n - 1, d);
}

bool ktDong3(float a[][100], int m, int n, int d)
{
	if (n == 0)
		return 0;
	if (a[d][n - 1] < 0)
		return true;
	return ktDong3(a, m, n - 1, d);
}

void LietKe(float a[][100], int m, int n)
{
	if (m == 0)
		return;
	LietKe(a, m - 1, n);
	if (ktDong1(a, m, n, m - 1) && ktDong2(a, m, n, m - 1) && ktDong3(a, m, n, m - 1))
		cout << setw(10) << m - 1;
}