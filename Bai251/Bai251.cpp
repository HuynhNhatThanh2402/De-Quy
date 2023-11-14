#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TongCot(float[][100], int, int, int);
float TongNhoNhat(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran:";
	Xuat(b, k, l);

	cout << "\n\nTong cot nho nhat: " << TongNhoNhat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
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
		cout << fixed << setprecision(3) << setw(10) << a[m - 1][j];
}

float TongCot(float a[][100], int m, int n, int c)
{
	if (m == 0)
		return 0;
	return TongCot(a, m - 1, n, c) + a[m - 1][c];
}

float TongNhoNhat(float a[][100], int m, int n)
{
	if (n == 1)
		return TongCot(a, m, n, 0);
	float lc = TongNhoNhat(a, m, n - 1);
	if (TongCot(a, m, n, n - 1) < lc)
		lc = TongCot(a, m, n, n - 1);
	return lc;
}