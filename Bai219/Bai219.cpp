#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int TichCot(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	int c;
	cout << "\n\nNhap cot can tinh: ";
	cin >> c;

	cout << "\n\nTich cac so chan trong ma tran: " << TichCot(b, k, l, c);
	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> m;
	cout << "Nhap vao so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][100], int m, int n)
{
	if (m == 0)
		return;
	Xuat(a, m - 1, n);
	cout << endl;
	for (int j = 0; j < n; j++)
		cout << setw(10) << a[m - 1][j];
}

int TichCot(int a[][100], int m, int n, int c)
{
	if (m == 0)
		return 1;
	int s = TichCot(a, m - 1, n, c);
	if (a[m - 1][c] % 2 == 0)
		s = s * a[m - 1][c];
	return s;
}
