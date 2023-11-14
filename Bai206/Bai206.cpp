#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktChinhPhuong(int);
int TongChinhPhuong(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran:";
	Xuat(b, k, l);

	cout << "\n\nTong cac so chinh phuong tren cot co chi so le: " << TongChinhPhuong(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 201 - 100;
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

bool ktChinhPhuong(int n)
{
	if (n < 0)
		return false;
	for (int i = 0; i <= n; i++)
		if (n == i * i)
			return true;
	return false;
}

int TongChinhPhuong(int a[][100], int m, int n)
{
	if (m == 0)
		return 0;
	int s = TongChinhPhuong(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (ktChinhPhuong(a[m - 1][j]) && j % 2 != 0)
			s += a[m - 1][j];
	return s;
}