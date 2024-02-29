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
        cout <<"Nhap vao so cot: ";
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

void DichTraiXoayVongTheoChieuKimDongHoCacGiaTriNamTrenBien(int a[][MAX], int dong, int cot)
{
    int i, j;
    int temp = a[0][0]; 

    for (i = 0, j = 0; j < cot - 1; j++)
    {
        a[i][j] = a[i][j + 1];
    }
    for (i, j; i < dong - 1; i++)
    {
        a[i][j] = a[i + 1][j];
    }
    for (i, j; j > 0; j--)
    {
        a[i][j] = a[i][j - 1];
    }
    for (i, j; i > 1; i--)
    {
        a[i][j] = a[i - 1][j];
    }
    a[1][0] = temp;
}
int main()
{
    int a[MAX][MAX], dong, cot;
    int cot1, cot2;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    DichTraiXoayVongTheoChieuKimDongHoCacGiaTriNamTrenBien(a, dong, cot);
    cout << "Ma tran sau khi bien doi"<< endl;
    XuatMang(a, dong, cot);
    return 0;
}