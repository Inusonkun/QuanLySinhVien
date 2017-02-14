#include <iostream>
#include <iomanip>
#define MAX 100
using namespace std;

void vitricuoi(int a[], int n)
{
	cout <<"\nVi tri cuoi trong mang la: ";
	for(int i = 0; i < n; ++i)
	{
		if( i == n - 1)
		{
			cout << a[i] <<" nam o vi tri thu " << i;
		}
	}
}

int ktsnt(int x)
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
		for(int i = 3; i < sqrt((float)x); i +=2)
		{
			if( x % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

void snt_dautien(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		if(ktsnt(a[i]) == 1)
		{
			cout <<"\nSo nguyen to dau tien trong mang la: ";
			cout << a[i] <<" nam o vi tri tu "<< i;
			break;
		}
	}
}

void somin(int a[], int &n)
{
	int min = a[0];
	int i;
	for( i = 1; i < n; ++i)
	{
		if(min > a[i])
		{
			min = a[i];
		}
	}
	cout <<"\nGia tri nho nhat la: " << min;
}

void xuatmang(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << left << setw(5) << a[i];
	}
}

int main()
{
	int a[] = { 1, 5, 23, 11, 45, 32};
	int n = sizeof(a) / sizeof(a[0]);

	vitricuoi(a, n);
	snt_dautien(a, n);
	somin(a, n);
	system("pause");
	return 0;
}