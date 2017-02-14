#include <iostream>
#include <iomanip>
#define MAX 100
using namespace std;

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
		for(int i = 3; i < (int)sqrt((float)x); i +=2)
		{
			if( x % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

void tachmang_snt(int a[], int n, int b[], int &m)
{
	int i;
	m = 0;
	for( i = 0; i < n; ++i)
	{
		if(ktsnt(a[i]) == 1)
		{
			b[m++] = a[i];
		}
	}
}

void tachthanh2mang(int a[], int n, int b[], int &m, int c[], int &p)
{
	m = 0;
	p = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] >= 0)
		{
			b[m++] = a[i];
		}
		else
		{
			c[p++] = a[i];
		}
	}
}

void HoanVi(int &a, int &b)
{
	int temp ;
	temp = a;
	a = b;
	b = temp;
}

void interchangsort(int a[], int n, char phanbiet)
{
	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = i + 1; j < n; ++j)
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

void xuatmang(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << left << setw(4) << a[i];
	}
}

int main()
{
	int a[] = {2, -7, 31, -16, -10, 11};
	int b[MAX], m;
	int c[MAX], p;
	int n = sizeof(a) / sizeof(a[0]);

	cout <<"\nMang ban dau la: "; xuatmang(a, n);
	cout <<"\nMang cac so nguyen to duoc tach ra la: ";
	tachmang_snt(a, n, b, m);
	xuatmang(b, m);

	cout <<"\nMang da cho duoc tach thanh hai mang, ";
	tachthanh2mang(a, n, b, m, c, p);
	cout <<"mang so duong la: ";
	xuatmang(b, m);
	cout <<"\nmang so am la: ";
	xuatmang(c, p);

	cout <<"\nMang so da sap xep: ";
	interchangsort(a, n, 't');
	xuatmang(a, n);
	
	system("pause");
	return 0;
}