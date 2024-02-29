#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
using namespace std;
void NhapMang(int a[][MAX], int& dong, int& cot)

{
	do
	{
		cout<< ("\nNhap vao so dong: ");
		cin >> dong;
		if (dong < 1 || dong > MAX)
		{
			cout << ("\nSo dong khong hop le. Xin kiem tra lai!");
		}
	} while (dong < 1 || dong > MAX);
	do
	{
		cout << ("\nNhap vao so cot: ");
		cin >> cot;
		if (cot < 1 || cot > MAX)
		{
			cout << ("\nSo cot khong hop le. Xin kiem tra lai!");
		}
	} while (cot < 1 || cot > MAX);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << "Nhap vao a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}

void XuatMang(int a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout <<  a[i][j];
		}
		cout << ("\n\n");
	}
}

void TimGiaTriNhoNhatTren1Cot(int a[][100], int dong, int cot)
{

	for (int i = 0; i < cot; i++)
	{
		int Min = a[0][i];
		for (int j = 0; j < dong; j++)
		{
			Min = (Min < a[j][i]) ? Min : a[j][i];
		}
		cout << "\nCot "<< i;
		cout << " Gia tri min " << Min;
	}
}

int main()
{
	int a[MAX][MAX], dong, cot;
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	TimGiaTriNhoNhatTren1Cot(a, dong, cot);
	return 0;
}