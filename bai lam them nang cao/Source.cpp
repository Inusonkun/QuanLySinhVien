#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#define MAX 100
using namespace std;

void HoanVi(int &a, int &b)
{
	int temp;
	temp = a; 
	a = b; 
	b = temp;
}

void SapXep(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] < a[i+1])
		{
			HoanVi(a[i], a[i+1]);
		}
	}
}

int SoLonThu_k(int a[], int n, int k)
{
	int slt_k;
	for(int i = 0; i < n; i++)
	{
		
		slt_k = a[k - 1];
	}
	return slt_k;
}

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << left << setw(4) << a[i];
	}
}

int main()
{
	int a[MAX], n, k;
	do{
		cout <<"\nNhap so luong phan tu n = ";
		cin >> n;
		if(n < 0 || n > MAX)
		{
			cout <<"\nSo luong phan tu khong hop le! Hay nhap lai!";
		}
	}while(n < 0 || n > MAX);
	do{
	    cout <<"\nNhap so nguyen k = "; cin >> k;
	    if(k < 1 || k > n)
	    {
		    cout <<"\nSo nguyen k chi nam trong khoang tu 1 den n!";
	    }
	}while(k < 1 || k > n);

	srand(time(0));
	for(int i = 0; i < n; i++)
	{
		a[i] = 100 + rand() % 201;
	}
	XuatMang(a, n);

	cout <<"\nMang da sap xep theo thu tu giam gian: ";
	SapXep(a, n);
	XuatMang(a, n);

	cout <<"\nSo lon thu k la :" << SoLonThu_k(a, n, k);

	system("pause");
	system("cls");
	return main();
}