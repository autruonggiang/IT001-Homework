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
        a[i] = rand() % (300 - (-100) + 1) + (-100);
    }
}


void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void LietKe(int a[], int n)
{
    int i, j;
    int khoangCachGanNhat = (abs)(a[0] - a[1]);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            if ((abs)(a[i] - a[j]) < khoangCachGanNhat)
            {
                khoangCachGanNhat = (abs)(a[i] - a[j]);
            }
        }
    }
    cout << "Nhung cap gia tri gan nhau nhat : ";

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            if ((abs)(a[i] - a[j]) == khoangCachGanNhat)
            {
                cout << "vi tri cua a[" << i << "] va a[" << j << "]";
            }
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
    LietKe(a, n);
    return 0;
}