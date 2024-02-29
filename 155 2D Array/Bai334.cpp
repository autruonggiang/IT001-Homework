#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

using namespace std;

int NhapMang (float a[][MAX], int &dong, int &cot)
{
	do
	{
		cout << "\nNhap vao so dong: ";
		cin >> dong;

		if (dong < 1 || dong > MAX)
		{
			cout << "\nSo dong khong hop le. Vui long nhap lai !";
		}

	} while (dong < 1 || dong > MAX);

	do
	{
		cout << "\nNhap vao so cot: ";
		cin >> cot;

		if (cot < 1 || cot > MAX)
		{
			cout << "\nSo cot khong hop le. Vui long nhap lai !";

		}

	} while (cot < 1 || cot > MAX);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			float temp;
			cout << "\nNhap a[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> temp;
			a[i][j] = temp;
		}
	}
}

int XuatMang (float a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << a[i][j] << " ";
		}
			cout << "\n\n";
	}
}

int DemSoLuongSoDuong (float a[][MAX], int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] > 0)
			{
				dem++;
			}
		}
	}
	return dem;
}

int main ()
{
	float a[MAX][MAX];
	int dong, cot;
	NhapMang (a, dong, cot);
	XuatMang (a, dong, cot);

	int dem = DemSoLuongSoDuong (a, dong, cot);
	cout << "\nSo luong so duong trong ma tran = " << dem;
	
	return 0;
}
