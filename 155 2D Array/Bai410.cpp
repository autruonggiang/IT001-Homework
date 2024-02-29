#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <math.h>
#define MAX 100

using namespace std;

void NhapMang(int a[][MAX], int &dong, int &cot)
{
    do
    {
        cout << "\nNhap vao so dong: ";
        cin >> dong;

        if (dong < 1 || dong > MAX)
        {
            cout << "\nSo dong khong hop le. Xin kiem tra lai !";
        }

    } while (dong < 1 || dong > MAX);

    do
    {
        cout << "\nNhap vao so cot: ";
        cin >> cot;

        if (cot < 1 || cot > MAX)
        {
            cout << "\nSo cot khong hop le. Xin kiem tra lai !";

        }

    } while (cot < 1 || cot > MAX);
    
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "\nNhap a[" << i + 1 << "][" << j + 1 << "] = ";
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

void HoanVi(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void SapXepPhanTuTren1CotGiamDanTuTrenXuongDuoi(int a[][MAX], int dong, int cot, int y)
{
    for (int i = 0; i < dong - 1; i++)
    {
        for (int j = i + 1; j < dong; j++)
        {
            if (a[i][y] < a[j][y])
            {
                HoanVi(a[i][y], a[j][y]);
            }
        }
    }
}
int main()
{
    int a[MAX][MAX], dong, cot, y;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);

    do {
        cout << "\nNhap cot muon sap xep: 1+";
        cin >> y;
        if (y < 0 || y > cot - 1)
        {
            cout << "\nSo phan tu khong hop le. Xin kiem tra lai!";
        }
    } while (y < 0 || y > cot - 1);

    SapXepPhanTuTren1CotGiamDanTuTrenXuongDuoi(a, dong, cot, y);
    cout << "\nMa tran sau khi sap xep: \n";
    XuatMang(a, dong, cot);

    getch();
    return 0;
}
