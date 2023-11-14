#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float NhoNhat(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	int c;
	cout << "\n\nNhap cot can tinh: ";
	cin >> c;

	cout << "\n\nTich tren cot " << c << "trong ma tran : " << NhoNhat(b, k, l);
	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> m;
	cout << "Nhap vao so cot: ";
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

float NhoNhat(float a[][100], int m, int n)
{
	if (m == 0)
		return 0;
	int lc = NhoNhat(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (a[m - 1][j] < lc)
			lc = a[m - 1][j];
	return lc;
}
