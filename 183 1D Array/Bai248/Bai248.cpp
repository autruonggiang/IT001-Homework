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
        a[i] = rand() % (300 - (100) + 1) + (100);
    }
}


void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int KiemTraTangDan(int a[], int n)
{
    int flag = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main()
{
    int n;
    int a[MAX];
    nhap(a, n);
    xuat(a, n);
    cout << endl;
    int flag = KiemTraTangDan(a, n);
    if (flag == 1)
    {
        cout << "Mang tang dan";
    }
    else
    {
        cout << "Mang khong tang";
    }
    return 0;
}