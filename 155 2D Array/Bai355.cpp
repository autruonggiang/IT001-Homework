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

        if( dong < 1 || dong > MAX)
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

void LietKeCacDongToanAm(float a[][MAX], int dong, int cot)
{
    int flag;
    for (int i = 0; i < dong; i++)
    {
        flag = 1;
        for (int j = 0; j < cot; j++)
        {
            if(a[i][j] > 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "\nDong %d toan am la dong " << i + 1 << ": ";
            for (int j = 0; j < cot; j++)
            {
                cout << a[i][j] << " ";
            }
        }
    }
}

int main()
{
    float a[MAX][MAX];
    int dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    LietKeCacDongToanAm(a, dong, cot);

    return 0;
}