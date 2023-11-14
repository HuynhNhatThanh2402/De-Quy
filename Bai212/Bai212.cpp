#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float Tong(float[][100], int, int, float, float);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);

	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	float x;
	cout << "\nNhap x: ";
	cin >> x;

	float y;
	cout << "\nNhap y: ";
	cin >> y;

	cout << "\nTong cac gia tri nam trong doan [" << x << "," << y << "]: ";
	cout << fixed << setprecision(3) << Tong(b, k, l, x, y);
	cout << "\n\n\nKet thuc!!!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "\nNhap m: ";
	cin >> m;
	cout << "\nNhap n: ";
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

float Tong(float a[][100], int m, int n, float xx, float yy)
{
	if (m == 0)
		return 0;
	float s = Tong(a, m - 1, n, xx, yy);
	for (int j = 0; j < n; j++)
		if (a[m - 1][j] >= xx && a[m - 1][j] <= yy)
			s = s + a[m - 1][j];
	return s;
}