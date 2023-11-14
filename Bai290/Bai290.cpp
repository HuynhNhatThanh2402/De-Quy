#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void DichPhaiDong(float[][100], int, int, int);
void DichPhai(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Ma tran ban dau:";
	Xuat(b, k, l);

	DichPhai(b, k, l);
	cout << "\nMa tran sau khi dich phai:\n";
	Xuat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so hang: ";
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
		cout << setw(8) << setprecision(3) << a[m - 1][j];
}

void DichPhaiDong(float a[][100], int m, int n, int d)
{
	float temp = a[d][n - 1];
	for (int j = n - 1; j >= 1; j--)
		a[d][j] = a[d][j - 1];
	a[d][0] = temp;
}

void DichPhai(float a[][100], int m, int n)
{
	if (m == 0)
		return;
	DichPhai(a, m - 1, n);
	DichPhaiDong(a, m, n, m - 1);
}