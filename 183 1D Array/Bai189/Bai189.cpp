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
int TimChuSoDauLe(int n)
{
    int dv;
    while (n >= 10)   // vòng lặp kết thúc khi n < 10
    {
        dv = n % 10;
        n = n / 10;
    }
    if (n % 2 == 0)
        return 0;
    return 1;
}

int LietKeViTriChuSoDauLe(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (TimChuSoDauLe(a[i]) == 1)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}

int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    cout << endl;
    cout << "Cac so co chu so dau le la : " << endl;
    LietKeViTriChuSoDauLe(a, n);
    return 0;
}