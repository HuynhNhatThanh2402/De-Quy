#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void HoanViCot(int[][100], int, int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "Mang vua nhap: ";
	Xuat(b, k, l);

	int c1;
	cout << "\n\nNhap cot thu nhat: ";
	cin >> c1;

	int c2;
	cout << "\nNhap cot thu hai: ";
	cin >> c2;

	HoanViCot(b, k, l, c1, c2);
	cout << "\n\nMa tran sau hoan vi: ";
	Xuat(b, k, l);

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

void HoanViCot(int a[][100], int m, int n, int c1, int c2)
{
	if (m == 0)
		return;
	HoanViCot(a, m - 1, n, c1, c2);
	swap(a[m - 1][c1], a[m - 1][c2]);
}
