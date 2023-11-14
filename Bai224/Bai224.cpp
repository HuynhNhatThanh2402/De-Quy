#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TichCot(float[][100], int, int, int);

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

	if (TichCot(b, k, l, c) == 1)
		cout << "Mang khong chua gia tri thuoc doan [-1,0]!";
	else
		cout << "\n\nTich tren cot " << c << "trong ma tran : " << TichCot(b, k, l, c);
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

float TichCot(float a[][100], int m, int n, int c)
{
	if (m == 0)
		return 1;
	float s = TichCot(a, m - 1, n, c);
	if (a[m - 1][c] >= -1 && a[m - 1][c] <= 0)
		s = s + a[m - 1][c];
	return s;
}
