#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAX 100
using namespace std;
void nhap(int a[], int& n)
{
    srand(time(NULL));

    cout << "Nhap so phan tu: ";
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (100 - (-100) + 1) + (-100);
    }
}


void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int DemSoLuongCacGiaTriPhanBiet(int a[], int n)
{
    int dem = 0, flag;
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            dem++;
        }
    }
    return dem;
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    int dem = DemSoLuongCacGiaTriPhanBiet(a, n);
    cout << "So luong cac gia tri phan biet trong mang = " << dem;
    return 0;
}