#include <iostream>
#include <iomanip>
#define MAX 100
using namespace std;

int ktsnt(int &x)
{
	if(x < 2)
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
			if( x % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

void ChangeArray(int a[], int n)
{
	for(int i =0; i < n; ++i)
	{
		if(ktsnt(a[i]) == 1)
		{
			a[i] = 0;
		}
	}
}

void ThemPhanTu(int a[], int &n, int vitri, int phantumoi)
{
	for(int i = n - 1; i >= vitri; --i)
	{
		a[i + 1] = a[i];
	}
	a[vitri] = phantumoi;
	n++;
}

void InsertArray(int a[], int &n)
{
	for(int i = 0; i < n; ++i)
	{
		if(ktsnt(a[i]) == 1)
		{
			ThemPhanTu(a, n, i + 1, 0);
			i++;
		}
	}
}

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << left << setw(4) << a[i];
	}
}

int main()
{
	int a[MAX] = { -1, 23, 10, 11, 15, 33};
	int n = 6;

	cout <<"\nThay doi cac so nguyen to trong mang thanh so 0: ";
	ChangeArray(a, n);
	XuatMang(a, n);

	cout <<"\nChen so 0 vao sau tat ca cac so nguyen to trong mang: ";
	InsertArray(a, n);
	XuatMang(a, n);

	system("pause");
	return 0;
}