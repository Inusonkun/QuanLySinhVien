#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define MAX 100
using namespace std;

void ktmangchan(int a[], int n)
{
	int dem = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] % 2 != 0)
		{
			dem++;
		}
	}
	if(dem != 0)
	{
		cout <<"\nDay khong  phai la mang chan";
	}
	else 
	{
	    cout <<"\nDay la mang chan";
	}
}
void ktsonguyento(int a[], int n)
{
	int dem = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] < 2)
		{
			dem++;
		}
		else if(a[i] > 2)
		{
			if(a[i] % 2 == 0)
			{
				dem++;
			}
			for(int j = 3; j <= (int)sqrt((float)a[i]); j++)
			{
				if(a[i] % j == 0)
				{
					dem++;
				}
			}
		}
	}
	if( dem != 0)
	{
		cout <<"\nMang khong phai toan la so nguyen to";
	}
	else
	{
		cout <<"\nMang toan la so nguyen to";
	}
}

//Tim so duong nho nhat trong mang??
int TimSoDuongMin(int a[], int n)
{
	int vitrisoduongdautien = -1;
	for(int i = 0; i < n; i++)
	{
		if(a[i] >= 0)
		{
			vitrisoduongdautien = i;
			break;
		}
	}

	int min = a[vitrisoduongdautien];
	if(vitrisoduongdautien != -1)
	{
	    for(int j = vitrisoduongdautien + 1; j < n; j++)
	    {
		     if(a[j] > 0 && a[j] < min)
		     {
			      min = a[j];
		     }
	    }
		return min;
	}
	else 
	{
		return -1;
	}
}

void xuatmang(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << left << setw( 4) << a[i];
	}
}

int main()
{
	int a[MAX], n;
	do{
		cout <<"\nNhap so luong phan tu: ";
		cin >> n;
		if(n < 0 || n > MAX)
		{
			cout <<"\nSo luong phan tu khong hop le! Hay nhap lai!";
		}
	}while(n < 0 || n > MAX);

	srand(time(0));
	for(int i = 0; i < n; i++)
	{
		a[i] = -20 + rand() % 51;
	}

	xuatmang(a, n);

	ktmangchan(a, n);

	ktsonguyento(a, n);

	cout <<"\nSo duong nho nhat la: " << TimSoDuongMin(a, n);

	system("pause");
	system("cls");
	return main();
}