#include<stdio.h>
#include <iostream>
#include <conio.h>
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
        for(int j = 0; j < cot; j++)
        {
            cout << "\nNhap a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMang(int a[][MAX], int dong, int cot)
{
    for(int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            cout << a[i][j] << " ";
        }
            cout << "\n\n";
    }
}

int KiemTraNguyenTo(int n)
{
    if(n < 2)
    {
        return 0;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return 0;
        }
        
        for (int i = 3; i <= sqrt((float)n); i+= 2)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void LietKeDongChuaSoNguyenTo(int a[][MAX], int dong, int cot)
{
    int flag;
    for (int i = 0; i < dong; i++)
    {
        flag = 0;
        for (int j = 0; j < cot; j++)
        {
            if(KiemTraNguyenTo(a[i][j]) == 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "\nDong a[" << i + 1 <<"] co chua so nguyen to "; 
        }    
    }
}

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    LietKeDongChuaSoNguyenTo(a, dong, cot);
    getch();
    return 0;
}
