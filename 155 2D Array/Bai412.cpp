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
        cout <<"\n\n";
    }
}
void HoanVi(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int KiemTraNguyenTo(int n)
{
    if (n < 2)
    {
        return 0;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return 0;
        }
        for (int i = 3; i <= sqrt((float)n); i += 2)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
void XuatCacSoNguyenToTheoThuTuTangDan(int a[][MAX], int dong, int cot)
{
    int temp[MAX];
    int idx = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (KiemTraNguyenTo(a[i][j]) == 1)
            {
                temp[idx++] = a[i][j];
            }
        }
    }
    for (int i = 0; i < idx - 1; i++)
    {
        for (int j = i + 1; j < idx; j++)
        {
            if (temp[i] > temp[j])
            {
                HoanVi(temp[i], temp[j]);
            }
        }
    }
    cout << "Xuat cac so nguyen to theo thu tu tang dan: \n";
    for (int i = 0; i < idx; i++)
    {
        cout << temp[i] << " " << endl;
    }
}
int main()
{
    int a[MAX][MAX], dong, cot, y;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    XuatCacSoNguyenToTheoThuTuTangDan(a, dong, cot);
    return 0;
}