#include <iostream>
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
    a = a + b;
    b = a - b;   
    a = a - b;  
}

void SapXepAmTangDan(int a[][MAX], int dong, int cot)
{
    int i, j, Start1, Start2, d = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] < 0)
            {
                for (Start1 = i; Start1 < dong; Start1++)
                {
                    if (d == 0)
                    {
                        Start2 = j;
                    }
                    else
                    {
                        Start2 = 0;
                    }
                    for (; Start2 < cot; Start2++)
                    {
                        if (a[i][j] > a[Start1][Start2] && a[Start1][Start2] < 0)
                        {
                            HoanVi(a[i][j], a[Start1][Start2]);
                        }
                    }
                    if (Start2 == cot)
                    {
                        d = 1;
                    }
                }
                d = 0;
            }
        }
    }
}

void SapXepDuongGiamDan(int a[][MAX], int dong, int cot)
{
    int i, j, Start1, Start2, d = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] > 0)
            {
                for (Start1 = i; Start1 < dong; Start1++)
                {
                    if (d == 0)
                    {
                        Start2 = j;
                    }
                    else
                    {
                        Start2 = 0;
                    }
                    for (; Start2 < cot; Start2++)
                    {
                        if (a[i][j] < a[Start1][Start2] && a[Start1][Start2] > 0)
                        {
                            HoanVi(a[i][j], a[Start1][Start2]);
                        }
                    }
                    if (Start2 == cot)
                    {
                        d = 1;
                    }
                }
                d = 0;
            }
        }
    }
}

void SapXepAmTangDanDuongGiamDan0GiuNguyenViTri(int a[][MAX], int dong, int cot)
{
    SapXepAmTangDan(a, dong, cot);
    SapXepDuongGiamDan(a, dong, cot);
}

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    SapXepAmTangDanDuongGiamDan0GiuNguyenViTri(a, dong, cot);
    cout << "\nMa tran sau khi sap xep: \n";
    XuatMang(a, dong, cot);
    
    return 0;
}
