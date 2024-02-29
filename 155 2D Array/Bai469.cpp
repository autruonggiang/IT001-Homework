#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
using namespace std;
void NhapMaTran(int a[][MAX], int& dong, int& cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "Nhap a[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int a[][MAX], int dong, int cot)
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

void TinhTong2MaTran(int a[][MAX], int b[][MAX], int c[][MAX], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
int main()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], dong, cot;
    do
    {
        cout << "\nNhap vao so dong: ";
        cin >> dong;

        if (dong < 1 || dong > MAX)
        {
            printf("\nSo dong khong hop le. Xin kiem tra lai!");
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
    cout << "Nhap vao ma tran A: ";
    NhapMaTran(a, dong, cot);

    cout << "Nhap vao ma tran B: ";
    NhapMaTran(b, dong, cot);

    cout << "Ma tran A vua nhap: ";
    XuatMaTran(a, dong, cot);

    cout << "Ma tran B vua nhap : ";
    XuatMaTran(b, dong, cot);

    TinhTong2MaTran(a, b, c, dong, cot);
    cout << "Ma tran C = A + B " << endl;
    XuatMaTran(c, dong, cot);
    return 0;
}