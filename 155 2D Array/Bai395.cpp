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
        cout << "Nhap vao so dong: ";
        cin >> dong;

        if (dong < 1 || dong > MAX)
        {
            cout << "So dong khong hop le. Xin kiem tra lai!";
        }

    } while (dong < 1 || dong > MAX);

    do
    {
        cout << "Nhap vao so cot: ";
        cin >> cot;

        if (cot < 1 || cot > MAX)
        {
            cout << "So cot khong hop le. Xin kiem tra lai!";

        }

    } while (cot < 1 || cot > MAX);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "nhap vao a["<< i << "][" << j << "]: ";
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

void DichLenXoayVongCacHangTrongMaTran(int a[][MAX], int dong, int cot)
{
    int temp[MAX];
    for (int i = 0; i < cot; i++)
    {
        temp[i] = a[0][i];
    }
    for (int i = 0; i < dong - 1; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            a[i][j] = a[i + 1][j];
        }
    }
    for (int i = 0; i < cot; i++)
    {
        a[dong - 1][i] = temp[i];
    }
}

int main()
{
    int a[MAX][MAX], dong, cot;
    int cot1, cot2;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    DichLenXoayVongCacHangTrongMaTran(a, dong, cot);
    cout << "Ma tran sau khi dich len xoay vong cac hang: " <<endl;
    XuatMang(a, dong, cot);
    return 0;
}