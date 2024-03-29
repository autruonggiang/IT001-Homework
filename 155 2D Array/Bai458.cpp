#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
using namespace std;
void NhapMaTran(int a[][MAX], int& n)
{
    do
    {
        cout << "Nhap n: ";
        cin >> n;
        if (n < 1 || n > MAX)
        {
            cout << "So phan tu khong hop le.Xin kiem tra lai !";
        }
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap vao a["<<i+1<<"]["<<j+1<<"]";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << ("\n\n");
    }
}

int KiemTraMaTranCoDoiXungQuaDuongCheoPhu(int a[][MAX], int n)
{
    int flag = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[i][j] != a[n - 1 - j][n - 1 - i])
            {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    int a[MAX][MAX], n;
    NhapMaTran(a, n);
    XuatMaTran(a, n);

    int flag = KiemTraMaTranCoDoiXungQuaDuongCheoPhu(a, n);
    if (flag == 1)
    {
        cout << "Ma tran doi xung qua duong cheo phu!";
    }
    else
    {
        cout << "Khong thoa DK";
    }
    return 0;
}
