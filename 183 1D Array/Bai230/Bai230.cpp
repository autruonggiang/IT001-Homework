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
void LietKeTanSuatXuatHien(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int dem = 0;
        for (int j = 0; j < n; j++) 
        {
            if (a[i] == a[j])
            {
                if (i <= j)
                {
                    dem++;
                }
                else
                {
                    break;    
                }
            }
        }
        if (dem != 0)
        {
            cout << "Gia tri a[" << i << "] co tan suat xuat hien la " << dem << endl;
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
    LietKeTanSuatXuatHien(a, n);
    return 0;
}