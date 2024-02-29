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
int KiemTraToanLe(int n)
{
    int dv;
    while (n != 0)
    {
        dv = n % 10;
        if (dv % 2 == 0)
            return 0;
        n = n / 10;
    }
    return 1;
}

int TimSoToanChuSoLeMax(int a[], int n)
{
    int max;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (KiemTraToanLe(a[i]) == 1)
        {
            max = a[i]; // max lúc này là a[i]
            dem++;  // Đếm là 1
            break;     // lập tức thoát ra
        }
    }
    if (dem == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (KiemTraToanLe(a[i]) == 1)
        {
            max = (max > a[i]) ? max : a[i];
        }
    }
    return max;
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    int Kq = TimSoToanChuSoLeMax(a, n);
    cout << "so toan cac chu so le lon nhat la: " << Kq;
    return 0;
}