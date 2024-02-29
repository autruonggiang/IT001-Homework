#include <iostream>
#include<iomanip>
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
            cout << "\nNhap a[" << i + 1<< "][" << j + 1<< "] = ";
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

int TimPhanTuLonNhatDongICotJ(int a[][MAX], int dong, int cot, int i, int j)
{
    int Max = a[i][0];

    for (int k = 1; k < dong; k++)
    {
        Max = (Max < a[i][k]) ? a[i][k] : Max;
    }

    for (int k = 0; k < cot; k++)
    {
        Max = (Max < a[k][j]) ? a[k][j] : Max;
    }
    return Max;
}

void XayDungMaTranB(int a[][MAX], int dong, int cot, int b[][MAX])
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            b[i][j] = TimPhanTuLonNhatDongICotJ(a, dong, cot, i, j);
        }
    }
}
int main()
{
    int a[MAX][MAX],b[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    XayDungMaTranB(a, dong, cot, b);
    cout << "\nMa tran b[i][j] = lon nhat dong i, cot j cua ma tran A \n";
    XuatMang(b, dong, cot);

    return 0;
}
