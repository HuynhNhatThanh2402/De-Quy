#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void LietKe(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran:";
	Xuat(b, k, l);

	int cc;
	cout << "\n\nCot can liet ke: ";
	cin >> cc;
	cout << "\n\nCac so chan tren cot " << cc << " : ";
	LietKe(b, k, l, cc);

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

void LietKe(int a[][100], int m, int n, int c)
{
	if (m == 0)
		return;
	LietKe(a, m - 1, n, c);
	if (a[m - 1][c] % 2 == 0)
		cout << setw(6) << a[m - 1][c];
}