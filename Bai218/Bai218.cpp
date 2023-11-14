#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktDang5m(int);
int Tong5m(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	int d;
	cout << "\nNhap vi tri dong: ";
	cin >> d;

	cout << "\nTong cac gia tri thoa dieu kien: " << Tong5m(b, k, l, d);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
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

bool ktDang5m(int n)
{
	if (n == 1)
		return true;
	if (n == 0)
		return false;
	if (n % 5 != 0)
		return false;
	return ktDang5m(n / 5);
}

int Tong5m(int a[][100], int m, int n, int dd)
{
	if (n == 0)
		return 0;
	int s = Tong5m(a, m, n - 1, dd);
	if (ktDang5m(a[dd][n - 1]))
		s += a[dd][n - 1];
	return s;
}
