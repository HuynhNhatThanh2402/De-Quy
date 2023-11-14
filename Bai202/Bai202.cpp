#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktDoiXung(int);
void LietKe(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);
	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	int cc;
	cout << "\nNhap cot can kiem tra:";
	cin >> cc;

	cout << "\nCac gia tri doi xung tren cot " << cc << ":\n";
	LietKe(b, k, l, cc);
	cout << "\n\n\nKet thuc!!!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "\nNhap m: ";
	cin >> m;
	cout << "\nNhap n: ";
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

bool ktDoiXung(int x)
{
	x = abs(x);
	int k = x;
	int dn = 0;
	while (k != 0)
	{
		int dv = k % 10;
		dn = dn * 10 + dv;
		k = k / 10;
	}
	if (dn == x)
		return true;
	return false;
}

void LietKe(int a[][100], int m, int n, int c)
{
	if (m == 0)
		return;
	LietKe(a, m - 1, n, c);
	if (ktDoiXung(a[m - 1][c]))
		cout << setw(10) << a[m - 1][c];
}
