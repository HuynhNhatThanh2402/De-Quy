#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktHoanThien(int); 
int DemHoanThien(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	cout << "\n\nSo luong so hoan thien: " << DemHoanThien(b, k, l);

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

bool ktHoanThien(int n)
{
	if (n == 0)
		return false;
	int s = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			s += i;
	if (s == n)
		return true;
	return false;
}

int DemHoanThien(int a[][100], int m, int n)
{
	if (m == 0)
		return 0;

	int dem = DemHoanThien(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (ktHoanThien(a[m - 1][j]))
			dem++;
	return dem;
}
