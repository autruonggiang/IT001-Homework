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
            cout << "So dong khong hop le.Xin kiem tra lai!";
        }

    } while (dong < 1 || dong > MAX);
    do
    {
        cout << "Nhap vao so cot : ";
        cin >> cot;

        if (cot < 1 || cot > MAX)
        {
            cout << "So cot khong hop le.Xin kiem tra lai!";

        }

    } while (cot < 1 || cot > MAX);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "Nhap a[" << i << "][" << j << "]: ";
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
            cout << a[i][j] << "\t";
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

void SapXepCotCoChiSoChanGiamDanLeTangDan(int a[][MAX], int dong, int cot)
{
    for (int i = 0; i < cot; i++)
    {
        for (int j = 0; j < dong - 1; j++)
        {
            for (int k = j + 1; k < dong; k++)
            {
                if (i % 2 == 0)
                {
                    if (a[j][i] < a[k][i])
                    {
                        HoanVi(a[j][i], a[k][i]);
                    }
                }
                else
                {
                    if (a[j][i] > a[k][i])
                    {
                        HoanVi(a[j][i], a[k][i]);
                    }
                }
            }
        }
    }
}
int main()
{
    int a[MAX][MAX], dong, cot, y;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);


    SapXepCotCoChiSoChanGiamDanLeTangDan(a, dong, cot);
    cout << "\nMa tran sau khi sap xep: \n" << endl << "\t";
    XuatMang(a, dong, cot);
    return 0;
}