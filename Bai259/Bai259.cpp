#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

bool ktDong(float[][100], int, int, int);
void LietKeDong(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	cout << "\n\nCac dong chua gia tri am trong ma tran: ";
	LietKeDong(b, k, l);

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

bool ktDong(float a[][100], int m, int n, int d)
{
	if (n == 0)
		return false;
	if (a[d][n - 1] < 0)
		return true;
	return ktDong(a, m, n - 1, d);
}

void LietKeDong(float a[][100], int m, int n)
{
	if (m == 0)
		return;
	LietKeDong(a, m-1, n);
	if (ktDong(a, m, n, m - 1))
		cout << setw(10) << (m - 1);

}