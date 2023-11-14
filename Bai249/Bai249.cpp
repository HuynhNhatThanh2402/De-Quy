#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktChinhPhuong(int);
int ChinhPhuongLonNhat(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	if (ChinhPhuongLonNhat(b, k, l) == 0)
		cout << "\n\nMa tran khong ton tai so chinh phuong";
	else
		cout << "\n\nSo chinh phuong lon nhat:  " << ChinhPhuongLonNhat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> m;
	cout << "Nhap vao so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
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

bool ktChinhPhuong(int n)
{
	for (int i = 0; i < n; i++)
		if (i * i == n)
			return true;
	return false;
}

int ChinhPhuongLonNhat(int a[][100], int m, int n)
{
	if (m == 0)
		return 0;
	int lc = ChinhPhuongLonNhat(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (ktChinhPhuong(a[m - 1][j]))
			if (a[m - 1][j] > lc)
				lc = a[m - 1][j];
	return lc;
}
