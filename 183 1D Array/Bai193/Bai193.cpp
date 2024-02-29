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
        a[i] = rand() % 300 +1;
    }
}


void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int KiemTraDang3K(int n)
{
    int flag = 1;
    n = n < 0 ? -n : n;
    if (n < 2)
        return 1;

    while (n > 1)
    {
        int du = n % 3;
        if (du != 0)  
            flag = 0;
        n /= 3;
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}

void LietKeCacGiaTriCoDang3K(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (KiemTraDang3K(a[i]) == 1)
        {
            cout << a[i] << " ";
        }
    }
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    cout << "Cac gia tri co dang 3 ^ k trong mang la : " << endl;
    LietKeCacGiaTriCoDang3K(a, n);
    return 0;
}