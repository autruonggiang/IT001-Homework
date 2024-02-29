#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100

using namespace std;

void NhapMaTran(int a[][MAX], int &n)
{
    do
    {
        cout << "\nNhap n: ";
        cin >> n;
        if (n < 1 || n > MAX)
        {
            cout << "\nSo phan tu khong hop le. Xin kiem tra lai !";
        }
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\nNhap vao a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int a[][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n\n";
    }
}

void Tim2GiaTriGanNhauNhat(int a[][MAX], int n, int &x1, int &x2)
{
    int KhoangCach = abs(a[0][0] - a[0][1]); 
    x1 = a[0][0];
    x2 = a[0][1];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == n - 1 && j == n - 1) 
            {
                break;
            }
            for (int k = i; k < n; k++)
            {
                for (int h = 0; h < n; h++)
                {
                    if (k == i && h <= j)
                    {
                        continue;
                    }
                    if (KhoangCach > abs(a[i][j] - a[k][h]))
                    {
                        KhoangCach = abs(a[i][j] - a[k][h]);
                        x1 = a[i][j];
                        x2 = a[k][h];
                    }
                }
            }
        }
    }
}

int main()
{
    int a[MAX][MAX], n, x1, x2;
    NhapMaTran(a,n);
    XuatMaTran(a,n);

    Tim2GiaTriGanNhauNhat(a, n, x1, x2);
    cout << "\n2 Gia tri gan nhau nhat la " << x1 << " va " << x2;
    
    return 0;
}
