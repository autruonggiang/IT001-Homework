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
            cout << "So cot khong hop le.Xin kiem tra lai!";

        }

    } while (cot < 1 || cot > MAX);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "Nhap a[" << i << "][" << j << "]";
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
            cout << a[i][j];
        }
        cout << "\n\n";
    }
}

void HoanVi(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void HoanVi2Cot(int a[][MAX], int dong, int cot, int cot1, int cot2)
{
    if ((cot1 >= 0 && cot1 < cot) && (cot2 >= 0 && cot2 < cot))
    {
        for (int i = 0; i < dong; i++)
        {
            HoanVi(a[i][cot1], a[i][cot2]);
        }
    }
}

void DichPhaiXoayVongCacCotTrongMaTran(int a[][MAX], int dong, int cot)
{
    for (int j = cot - 1; j > 0; j--)
    {
        for (int i = 0; i < dong; i++)
        {
            HoanVi(a[i][j], a[i][j - 1]);
        }
    }
}
int main()
{
    int a[MAX][MAX], dong, cot;
    int cot1, cot2;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    DichPhaiXoayVongCacCotTrongMaTran(a, dong, cot);
    cout << "Ma tran sau khi dich phai xoay vong cac cot: "<< endl;
    XuatMang(a, dong, cot);
    return 0;
}