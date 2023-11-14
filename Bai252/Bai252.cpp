#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
bool TonTaiDuong(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);

	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	if (TonTaiDuong(b, k, l))
		cout << "\nMa tran co ton tai so duong";
	else
		cout << "\nMa tran khong ton tai so duong";
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

bool TonTaiDuong(float a[][100], int m, int n)
{
	if (m == 0)
		return false;
	for (int j = 0; j < n; j++)
		if (a[m - 1][j] > 0)
			return true;
	return TonTaiDuong(a, m - 1, n);
}