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

int TimChanDauTien(int a[][MAX], int dong, int cot) 
{ 
    for (int i = 0; i < dong; i++) 
    { 
        for (int j = 0; j < cot; j++) 
        { 
            if (a[i][j] % 2 == 0) 
            { 
                return a[i][j]; 
            } 
        } 
    } 
    return -1; 
} 

int TimChanMin(int a[][MAX], int dong, int cot) 
{ 
    int ChanMin = TimChanDauTien(a, dong, cot); 
    if (ChanMin == -1) 
    { 
        return -1; 
    } 
    for (int i = 0; i < dong;i++) 
    { 
        for (int j = 0; j < cot; j++) 
        { 
            if (a[i][j] % 2 == 0) 
            { 
                ChanMin = (ChanMin < a[i][j]) ? ChanMin : a[i][j]; 
            } 
        } 
    } 
    return ChanMin; 
} 
int DemSoLuongGiaTriChanMin(int a[][MAX], int dong, int cot)
{
    int dem = 0;
    int min = TimChanMin(a, dong, cot);
    for (int i = 0; i < dong; i++) 
    { 
        for (int j = 0; j < cot; j++) 
        { 
            if (min == a[i][j]) 
            { 
                dem++ ; 
            } 
        } 
    } 
    return dem; 
}

int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);

    int dem = DemSoLuongGiaTriChanMin(a, dong, cot);
    cout << "\nSo luong gia tri chan nho nhat la " << dem;

    return 0;
}
