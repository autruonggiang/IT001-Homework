#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

using namespace std;

void NhapMang(float a[][MAX], int &dong, int &cot)
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
            float temp;
            cout << "\nNhap a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> temp;
            a[i][j] = temp;
        }
    }
}

void XuatMang(float a[][MAX], int dong, int cot)
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

int DemSoLuongSoDuongTren1Dong(float a[][MAX], int x, int cot)
{
    int dem = 0;
    for(int j = 0; j < cot; j++)
    {
        if(a[x][j] > 0)
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    float a[MAX][MAX];
    int dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);

    int x;
    do{
        cout << "\nNhap vao dong x can dem: ";
        cin >> x;

        if (x < 0 || x > dong - 1)
        {
            cout << "\nChi so dong x khong hop le. Xin kiem tra lai !";
        }
    } while (x < 0 || x > dong - 1);
    
    int dem = DemSoLuongSoDuongTren1Dong(a, x, cot);
    cout << "\nSo luong so duong tren mot dong = " << dem;

    return 0;
}
