#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void SapCotGiam(float[][100], int, int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Nhap ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	int c;
	cout << "\nNhap vi tri cot: ";
	cin >> c;

	SapCotGiam(b, k, l, c);
	cout << "\nSau khi sap xep: \n";
	Xuat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
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
		cout << fixed << setw(10) << setprecision(3) << a[m - 1][j];
}

void SapCotGiam(float a[][100], int m, int n, int cc)
{
	if (m == 0)
		return;
	for (int i = 0; i <= m - 2; i++)
		if (a[i][cc] < a[m - 1][cc])
			swap(a[i][cc], a[m - 1][cc]);
	SapCotGiam(a, m - 1, n, cc);
}
