#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
using namespace std;
void nhapmang(int a[][MAX], int& m, int& n);
void xuatmang(int a[][MAX], int m, int n);
int toanduong(int a[][MAX], int m, int n);
void main()
{
	int a[MAX][MAX], m, n, x, vtd, vtc;
	nhapmang(a, m, n);
	cout << ("\nnoi dung cua ma tran\n");
	xuatmang(a, m, n);
	if (toanduong(a, m, n) == -1)
		cout << ("\nMa tran khong toan duong");
	else
		cout << ("\nMa tran toan so duong ");
}
void nhapmang(int a[][MAX], int& m, int& n)
{
	int i, j;
	do
	{
		cout << ("nhap vao so dong cua ma tran: ");
		cin >> m;
	} while (m <= 0);
	do
	{
		cout << ("nhap vao so cot cua ma tran: ");
		cin >> n;
	} while (n <= 0);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "Nhap vao a[" << i << "][" << j<<"]";
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
			cout << a[i][j];
		}
		cout << ("\n");
	}
}
int toanduong(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < 0)
			{
				return -1;
				break;
			}
		}
	}
	return 1;
}