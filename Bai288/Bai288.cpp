#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void DichLenCot(float[][100], int, int, int);
void DichLen(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	DichLen(b, k, l);
	cout << "\nSau khi dich len:\n";
	Xuat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
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

void DichLenCot(float a[][100], int m, int n, int c)
{
	float temp = a[0][c];
	for (int i = 0; i <= m - 2; i++)
		a[i][c] = a[i+1][c];
	a[m - 1][c] = temp;
}

void DichLen(float a[][100], int m, int n)
{
	if (n == 0)
		return;
	DichLen(a, m, n - 1);
	DichLenCot(a, m, n, n - 1);
}