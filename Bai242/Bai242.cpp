#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktNguyenTo(int);
int NguyenToDau(int[][100], int, int);
int main()
{
	int b[100][100];
	int k, l;

	cout << "Nhap ma tran:\n";
	Nhap(b, k, l);
	cout << "\nMa tran vua nhap:\n";
	Xuat(b, k, l);

	if (NguyenToDau(b, k, l) == -1)
		cout << "\nMa tran khong co so nguyen to.";
	else
		cout << "\nSo nguyen to dau tien cua ma tran: " << NguyenToDau(b, k, l);
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

bool ktNguyenTo(int x)
{
	int dem = 0;
	for (int i = 1; i <= x; i++)
		if (x % i == 0)
			dem++;
	if (dem == 2)
		return true;
	return false;

}

int NguyenToDau(int a[][100], int m, int n)
{
	if (m == 0)
		return -1;
	int lc = NguyenToDau(a, m - 1, n);
	if (lc != -1)
		return lc;
	for (int j = 0; j < n; j++)
		if (ktNguyenTo(a[m - 1][j]))
			return a[m - 1][j];
	return -1;
}
