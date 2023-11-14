#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void NguyenHoa(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	Nhap(b, k, l);

	cout << "\nMa tran ban dau:";
	Xuat(b, k, l);

	cout << "\n\nMa tran luc sau: ";
	NguyenHoa(b, k, l);
	Xuat(b, k, l);

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

void NguyenHoa(float a[][100], int m, int n)
{
	if (m == 0)
		return;
	NguyenHoa(a, m - 1, n);
	for (int j = 0; j < n; j++)
		if (a[m - 1][j] > 0)
			a[m - 1][j] = int(a[m - 1][j] + 0.5);
		else
			a[m - 1][j] = int(a[m - 1][j] - 0.5);
}