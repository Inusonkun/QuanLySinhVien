#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define MAX 100
using namespace std;

int KiemTraSoNguyenTo(int x)
{
	if( x < 2)
	{
		return 0;
	}
	else if(x > 2)
	{
		if( x % 2 == 0)
		{
			return 0;
		}

		for(int i = 3; i <= (int)sqrt((float)x); i +=2)
		{
			if(x % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

void TachMangSoNguyenTo(int a[], int n, int b[], int &m)
{
	int i;
	m = 0;
	for(i = 0; i < n; i++)
	{
		if(KiemTraSoNguyenTo(a[i]) == 1)
		{
			b[m++] = a[i];
		}
	}
}

void TachThanhHaiMangAmDuong(int a[], int n, int b[], int &m, int c[], int &k)
{
	m = k = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > 0)
		{
			b[m++] = a[i];
		}
		else
		{
			c[k++] = a[i];
		}
	}
}

void HoanVi(int &a, int &b)
{
	b = a + b;
	a = b - a; // a = a + b - a = b
	b = b - a; // b = a + b - b
}

void InterChangeSort(int a[], int n, char phanbiet)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(phanbiet == 't')
			{
				if(a[i] > a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
			else if(phanbiet == 'g')
			{
				if(a[i] < a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}

void SapXepDuongGiamAmTang(int a[], int n, int b[], int m, int c[], int k)
{
	InterChangeSort(b, m, 'g');
	InterChangeSort(c, k, 't');

	int i;
	for( i = 0; i < m; i++)
	{
		a[i] = b[i];
	}
	for(int j = 0; j < k; j++)
	{
		a[i++] = c[j];
	}
}

void XUATMANG(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << left << setw(4) << a[i];
	}
}

int main()
{
	int a[MAX], n;
	do{
		cout <<"\nNhap so luong phan tu n = ";
		cin >> n;
		if(n < 0 || n > MAX)
		{
			cout <<"\nSo luong phan tu khong hop le!";
		}
	}while(n < 0 || n > MAX);
	srand(time(0));  // random so luong phan tu trong khoang tu -20 --> 30
	for(int i = 0; i < n; i++)
	{
		a[i] = -20 + rand() % 51; // a[i] = -20 + rand() % (30 -(-20) + 1)
	}
	XUATMANG(a, n);

	int b[MAX], m;
	cout <<"\nMang so nguyen to duoc tach ra la: ";
	TachMangSoNguyenTo(a, n, b, m);
	XUATMANG(b, m);

	int c[MAX], k;
	cout <<"\nMang da cho duoc tach thanh hai mang, ";
	TachThanhHaiMangAmDuong(a, n, b, m, c, k);

	cout <<"\nmang so duong la: ";
	XUATMANG(b, m);

	cout <<"\nva mang so am la: ";
	XUATMANG(c, k);

	cout <<"\nSap xep theo thu tu duong giam am tang so 0 o cuoi la: ";
	SapXepDuongGiamAmTang(a, n,b, m, c, k);
	XUATMANG(a, n);

	system("pause");
	system("cls");
	return main();
}