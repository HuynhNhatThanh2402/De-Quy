#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktDang2m(int);
void LietKe(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);

	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	cout << "\nCac gia tri dang 2m:\n";
	LietKe(b, k, l);
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

bool ktDang2m(int x)
{
	if (x < 1)
		return false;
	if (x == 1)
		return true;
	if (x % 2 == 0)
		return ktDang2m(x / 2);
	return false;
}

void LietKe(int a[][100], int m, int n)
{
	if (m == 0)
		return;
	LietKe(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (ktDang2m(a[m - 1][j]))
			cout << setw(10) << a[m - 1][j];

}
