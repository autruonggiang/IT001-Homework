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

int DemSoLuongGiaTriMin(int a[][MAX], int dong, int cot)
{
    int dem = 0;
    int min = a[0][0];
    for (int i = 0; i < dong; i++) 
    { 
        for (int j = 0; j < cot; j++) 
        { 
            if (min == a[i][j]) 
            { 
                dem++ ; 
            } 
            else if (a[i][j] < min) 
            { 
                min = a[i][j]; 
                dem = 1; 
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

    int dem = DemSoLuongGiaTriMin(a, dong, cot);
    cout << "\nSo luong gia tri nho nhat la " << dem;

    return 0;
}
