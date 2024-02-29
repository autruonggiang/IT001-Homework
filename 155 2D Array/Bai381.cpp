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

int DemSoLanXuatHienCuaX(int a[][MAX], int dong, int cot, int x)
{
    int temp = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] == x)
            {
                temp++;
            }
        }
    }
    return temp;
}

int TimGiaTriXuatHienNhieuNhat(int a[][MAX], int dong, int cot)
{
    int temp1, temp = DemSoLanXuatHienCuaX(a, dong, cot, a[0][0]), index1 = 0, index2 = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            temp1 = DemSoLanXuatHienCuaX(a, dong, cot, a[i][j]);
            if (temp < temp1)
            {
                temp = temp1;
                index1 = i;
                index2 = j;
            }
        }
    }
    return a[index1][index2];
}

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);

    int giatri = TimGiaTriXuatHienNhieuNhat(a, dong, cot);
    cout << "\nGia tri xuat hien nhieu nhat la " << giatri;

    return 0;
}
