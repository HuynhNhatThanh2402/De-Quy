#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void HoanViDong(float[][100], int, int, int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	int d1;
	cout << "\n\nNhap d1: ";
	cin >> d1;

	int d2;
	cout << "Nhap d2: ";
	cin >> d2;
	
	HoanViDong(b, k, l, d1, d2);
	cout << "\nSau khi hoan vi: \n";
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

void HoanViDong(float a[][100], int m, int n, int dd1, int dd2)
{
	if (n == 0)
		return;
	HoanViDong(a, m, n - 1, dd1, dd2);
	swap(a[dd1][n - 1], a[dd2][n - 1]);
}
