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
        a[i] = rand() % 300 + 1;
    }
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
bool KiemTraNguyenTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    else if (n > 2)
    {
        if (n % 2 == 0)
        {
            return false;
        }
        for (int i = 3; i <= sqrt((float)n); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int TimSoLonNhat(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        max = (max > a[i]) ? max : a[i];
    return max;
}

int TimNguyenToNhoNhatLonHonMoiGiaTriTrongMang(int a[], int n)
{
    int max = TimSoLonNhat(a, n);
    int SoCanTim = max + 1;
    for (SoCanTim = max + 1;; SoCanTim++)
    {
        if (max < SoCanTim)
        {
            if (KiemTraNguyenTo(SoCanTim) == 1)
                break;
        }
    }
    return SoCanTim;
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    int Kq = TimNguyenToNhoNhatLonHonMoiGiaTriTrongMang(a, n);
    cout << "So nguyen to nho nhat lon hon moi gia tri trong mang:  " <<  Kq;
    return 0;
}