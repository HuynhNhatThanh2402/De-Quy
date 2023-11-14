#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
bool ktCotGiam(float[][100], int, int, int);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);

	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	int cc;
	cout << "\nNhap cot can kiem tra: ";
	cin >> cc;

	if (ktCotGiam(b, k, l, cc))
		cout << "\nCot " << cc << " giam dan";
	else
		cout << "\nCot " << cc << " khong giam dan";
	cout << "\n\n\nKet thuc!!!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "\nNhap m: ";
	cin >> m;
	cout << "\nNhap n: ";
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

bool ktCotGiam(float a[][100], int m, int n, int c)
{
	if (m == 1)
		return true;
	if (a[m - 2][c] >= a[m - 1][c] && ktCotGiam(a, m - 1, n, c))
		return true;
	return false;
}