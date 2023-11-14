#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktToanChan(int);
int DemSoChan(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	cout << "\n\nSo luong so toan chan: " << DemSoChan(b, k, l);

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

bool ktToanChan(int n)
{
	n = abs(n);
	if (n <= 9)
	{
		if (n % 2 == 0)
			return true;
		return false;
	}
	int dv = n % 10;
	if (dv % 2 == 0 && ktToanChan(n / 10))
		return true;
	return false;
}

int DemSoChan(int a[][100], int m, int n)
{
	if (m == 0)
		return 0;
	int dem = DemSoChan(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (ktToanChan(a[m - 1][j]))
			dem++;
	return dem;
}
