#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int ktCotTang(float[][100], int, int, int);
void LietKe(float[][100], int, int); 

int main()
{
	float b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran:";
	Xuat(b, k, l);

	cout << "\n\nCac cot tang dan: ";
	LietKe(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
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
		cout << fixed << setprecision(3) << setw(10) << a[m - 1][j];
}

int ktCotTang(float a[][100], int m, int n, int c)
{
	if (m == 1)
		return 1;
	if (a[m - 2][c] <= a[m - 1][c] && ktCotTang(a, m - 1, n, c) == 1)
		return 1;
	return 0;
}

void LietKe(float a[][100], int m, int n)
{
	if (n == 0)
		return;
	LietKe(a, m, n - 1);
	if (ktCotTang(a, m, n, n - 1) == 1)
		cout << setw(6) << (n - 1);
}