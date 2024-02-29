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

void TachTungChuSo(int n, int b[])
{
    int ChuSo;
    n = abs(n);
    do
    {
        ChuSo = n % 10;
        b[ChuSo]++;
        n /= 10;
    } while (n > 0);
}

int TimChuSoXuatHienNhieuNhat(int a[][MAX], int dong, int cot)
{
    int b[10] = {0}; 
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            TachTungChuSo(a[i][j], b);
        }
    }
    int ChuSoXuatHienNhieuNhat = 0;
    for (int i = 0; i < 10; i++)
    {
        if (b[ChuSoXuatHienNhieuNhat] < b[i])
        {
            ChuSoXuatHienNhieuNhat = i;
        }
    }
    return ChuSoXuatHienNhieuNhat;
}

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);

    int ChuSoXuatHienNhieuNhat = TimChuSoXuatHienNhieuNhat(a, dong, cot);
    cout << "\nChu so xuat hien nhieu nhat la " << ChuSoXuatHienNhieuNhat;
    
    return 0;
}
