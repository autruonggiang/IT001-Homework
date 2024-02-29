#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

using namespace std;

void nhapmang(int a[][MAX], int &m, int &n);
void xuatmang(int a[][MAX], int m, int n);
double tongdong(int a[][MAX], int m, int n,int x);

void nhapmang(int a[][MAX], int &m, int &n)
{
	int i,j;
	do
	{
		cout << "Nhap vao so dong cua ma tran: ";
		cin >> m;
	} while (m <= 0);
	
	do
	{
		cout << "Nhap vao so cot cua ma tran: ";
		cin >> n;
	}
	while (n <= 0);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "\nSo phan tu a[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> a[i][j];
		}
	}
}
void xuatmang(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

double tongdong(int a[][MAX], int m, int n,int x)
{
	double sum = 0;
	for(int j = 0; j < n; j++)
		sum = sum + a[x][j];
	return sum;
}

int main()
{
	int a[MAX][MAX], m, n, x;
	nhapmang(a,m,n);
	cout << "\nNoi dung cua ma tran\n";
	xuatmang(a,m,n);
	cout << "\nNhap dong can tinh: 1 + ";
	cin >> x;
	double t = tongdong(a,m,n,x);
	cout << "\nTong dong " << x + 1 << " la: " << t;
	return 0;;
}
