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
        cout << ("\nNhap vao so dong: ");
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

int TimSoChanDauTien(int a[][MAX], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                return a[i][j];
            }
        }
    }
    return -1;
}

int TimSoChanLonNhat(int a[][MAX], int dong, int cot)
{
    int ChanMax = TimSoChanDauTien(a, dong, cot);
    if (ChanMax == -1)
    {
        return -1;
    }
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                ChanMax = (ChanMax > a[i][j]) ? ChanMax : a[i][j];
            }
        }
    }
    return ChanMax;
}
int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    int ChanMax = TimSoChanLonNhat(a, dong, cot);
    cout << "\nSo chan lon nhat trong ma tran = " << ChanMax;
    return 0;
}