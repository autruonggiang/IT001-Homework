#include<iostream>
#include<stdio.h>
#include<conio.h>
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

float duongcuoicung(float a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > 0)
        {
            return a[i];
        }
    }
    return -1;
}
int main()
{
    int n;
    float a[MAX];
    nhap(a, n);
    xuat(a, n);
    cout << endl;
    float duongcuoi = duongcuoicung(a, n);
    cout << "Gia tri duong cuoi cung la: " << duongcuoi;
    return 0;
}