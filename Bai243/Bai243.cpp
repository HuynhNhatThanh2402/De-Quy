#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float LonNhatDong(float[][100], int, int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	int d;
	cout << "\nNhap vi tri dong: ";
	cin >> d;

	cout << fixed << setprecision(3);
	cout << "\nGia tri lon nhat dong " << d << ": " << LonNhatDong(b, k, l, d);

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

float LonNhatDong(float a[][100], int m, int n, int dd)
{
	if (n == 1)
		return a[dd][0];
	float lc = LonNhatDong(a, m, n - 1, dd);
	if (a[dd][n - 1] > lc)
		lc = a[dd][n - 1];
	return lc;
}
