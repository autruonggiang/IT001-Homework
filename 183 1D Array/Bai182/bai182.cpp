#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAX 100
using namespace std;
void nhap(float a[], int& n)
{
    srand(time(NULL));

    cout << "Nhap so phan tu: ";
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (100 - (-100) + 1) + (-100);
    }
}


void xuat(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void LietKe(float a[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] * a[i - 1] < 0) || (a[i] * a[i + 1] < 0))
        {
            flag = 1;
            cout << a[i] << " ";
        }
    }
    if (flag == 0)
        cout << ("Mang ko co gia tri do");
}
int main()
{
    int n;
    float a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << ("\nCac so trong mang thoa dieu kien\n ");
    LietKe(a, n);
    return 0;
}