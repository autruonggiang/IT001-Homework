#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int a[100];
void main()
{
	int i, n, j, max, gt, dem;
	cout << "nhap so phan tu cua mang:";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << " Nhap vao a[" << i  << "]: ";
		cin >> a[i];
	}
	cout << "mang da nhap: " << endl;
	for (i = 0; i < n; i++) 
		cout << a[i] << " ";
	max = 1;
	for (i = 0; i < n; i++)
	{
		dem = 0;
		for (j = 0; j < n; j++)
		{
			if (a[i] == a[j]) dem++;
		}
		if (max < dem)
		{
			max = dem;
			gt = a[i];
		}
	}
	cout << endl;
	cout << "phan tu xuat hien nhieu nhat la : " << gt;
}