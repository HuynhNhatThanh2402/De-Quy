#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktDang2m(int);
int DemDang2m(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Ma tran ban dau:";
	Xuat(b, k, l);

	cout << "\nSo luong so nguyen co dang 2m: " << DemDang2m(b, k, l);

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
			a[i][j] = -100 + rand() / ((int)RAND_MAX / 200);
}

void Xuat(int a[][100], int m, int n)
{
	if (m == 0)
		return;
	Xuat(a, m - 1, n);
	cout << endl;
	for (int j = 0; j < n; j++)
		cout << setw(8) << setprecision(3) << a[m - 1][j];
}

bool ktDang2m(int k)
{
	if (k < 1)
		return false;
	bool flag = true;
	for (int t = k; t > 1; t = t / 2)
		if (t % 2 != 0)
			flag = false;
	return flag;
}

int DemDang2m(int a[][100], int m, int n)
{
	if (m == 0)
		return 0;
	int dem = DemDang2m(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (ktDang2m(a[m - 1][j]))
			dem++;
	return dem;
}