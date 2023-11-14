#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktHoanThien(int);
void LietKe(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Ma tran ban dau:";
	Xuat(b, k, l);

	int h;
	cout << "\nNhap dong can tim:";
	cin >> h;
	
	cout << "\nCac so hoan thien tren dong " << h << " : ";
	LietKe(b, k, l, h);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so hang: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			//cin >> a[i][j];
			a[i][j] = -100 + rand() / ((int)RAND_MAX / 200);
}

void Xuat(int a[][100], int m, int n)
{
	if (m == 0)
		return;
	Xuat(a, m - 1, n);
	cout << endl;
	for (int j = 0; j < n; j++)
		cout << setw(4) << a[m - 1][j];
}

bool ktHoanThien(int k)
{
	int s = 0;
	for (int i = 1; i <= k / 2; i++)
		if (k % i == 0)
			s = s + i;
	return (s == k);
}

void LietKe(int a[][100], int m, int n, int d) {
	if (n == 0)
		return;
	LietKe(a, m, n-1,d);
	if (ktHoanThien(a[d][n-1])==true)
			cout << setw(4) << a[d][n-1];
}