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
        a[i] = rand() % 300+1;
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
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && (a[i - 1] % 2 == 0 || a[i + 1] % 2 == 0))
        {
            flag = 1;
            printf("%4d", a[i]);
        }
    }
    if (flag == 0)
        cout << ("Mang ko co gia tri do");
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    cout << "Cac so trong mang thoa dieu kien ";
    LietKe(a, n);
    return 0;
}