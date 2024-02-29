#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <math.h>
#define MAX 100
#define MAX 100

using namespace std;
void NhapMang(int a[][MAX], int& cot, int& dong)
{
	do
	{
		cout << "Nhap vao so dong: ";
		cin >> dong;
		if (dong < 0 || dong > MAX)
		{
			cout << "so dong khong hop le. Kiem tra lai";
		}
	} while (dong < 0 || dong > MAX);
    do
    {
        cout << "Nhap vao so cot: ";
        cin >> cot;

        if (cot < 0 || cot > MAX)
        {
            cout << "So cot khong hop le. Xin kiem tra lai !";

        }

    } while (cot < 0 || cot > MAX);

    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "Nhap a[" << i + 1 << "][" << j + 1 << "] = ";
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
            cout << a[i][j] << " ";
        }
        cout << "\n\n";
    }

}
void HoanVi(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void XuatCacGiaTriChanTheoThuTuGiamDan(int a[][MAX], int dong, int cot)
{
    int temp[MAX];
    int idx = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                temp[idx++] = a[i][j];
            }
        }
    }
    for (int i = 0; i < idx - 1; i++)
    {
        for (int j = i + 1; j < idx; j++)
        {
            if (temp[i] < temp[j])
            {
                HoanVi(temp[i], temp[j]);
            }
        }
    }
    cout << "\nXuat cac gia tri chan theo thu tu giam dan: \n";
    for (int i = 0; i < idx; i++)
    {
        cout<< temp[i] <<" ";
    }
}
int main()
{
    int a[MAX][MAX];
    int dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    XuatCacGiaTriChanTheoThuTuGiamDan(a, dong, cot);
    return 0;
}