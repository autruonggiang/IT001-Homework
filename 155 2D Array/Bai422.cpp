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

void TinhTongCacDong(int a[][MAX], int dong, int cot, int b[])
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            b[i] += a[i][j];
        }
    }
}

void HoanVi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void HoanVi2Dong(int a[][MAX], int cot, int dong1, int dong2)
{
    for (int j = 0; j < cot; j++)
    {
        HoanVi(a[dong1][j], a[dong2][j]);
    }
}

void SapXepCacDongDuaVaoTongCacPhanTuTrong1Dong(int a[][MAX], int dong, int cot)
{
    int b[MAX] = {0};
    TinhTongCacDong(a, dong, cot, b);
    for (int i = 0; i < dong - 1; i++)  
    {   
        for (int j= i + 1; j < dong; j++)   
        {    
            if (b[i] > b[j])    
            {
                HoanVi2Dong(a, cot, i, j);
                HoanVi(b[i], b[j]);
            }
        }
    }
}

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    SapXepCacDongDuaVaoTongCacPhanTuTrong1Dong(a, dong, cot);
    cout << "\nMa tran sau khi sap xep: \n";
    XuatMang(a, dong, cot);

    return 0;
}
