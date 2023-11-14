#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktToanDuong(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Ma tran ban dau:";
	Xuat(b, k, l);

	if (ktToanDuong(b, k, l))
		cout << "\nMa tran toan duong";
	else
		cout << "\nMa tran khong toan duong";

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

int ktToanDuong(float a[][100], int m, int n)
{
	if (m == 0)
		return 1;
	int flag = ktToanDuong(a, m - 1, n);
	if (flag == 0)
		return flag;
	for (int j = 0; j < n; j++)
		if (a[m - 1][j] <= 0)
			return 0;
	return flag;
}