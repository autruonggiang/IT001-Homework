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
void SapXepKhongDungMangPhu(int a[][MAX], int dong, int cot)
{
    int n = dong * cot;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i / cot][i % cot] > 0)
            {
                if (a[i / cot][i % cot] > a[j / cot][j % cot])
                {
                    HoanVi (a[i / cot][i % cot], a[j / cot][j % cot]);
                }
            }
        }
    }
}

void SapXepDungMangPhu(int a[][MAX], int dong, int cot)
{
    int temp[MAX];
    int idx = 0;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            temp[idx++] = a[i][j];
        }
    }

    for (int i = 0; i < idx - 1; i++)
    {
        for (int j = i + 1; j < idx; j++)
        {
            if (temp[i] > 0)
            {
                if (temp[i] > temp[j])
                {
                    HoanVi(temp[i], temp[j]);
                }
            }
        }
    }

    idx = 0; 

    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            a[i][j] = temp[idx++];
        }
    }
}
int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    SapXepDungMangPhu(a, dong, cot);
    cout << "\nMa tran sau khi sap xep\n";
    XuatMang(a, dong, cot);

    return 0;
}
