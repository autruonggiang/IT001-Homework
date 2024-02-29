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
int DemSoLanXuatHienCuaMangATrongMangB(int a[], int b[], int na, int nb)
{
    int i, j, Start, flag, dem = 0;
    for (i = 0; i < nb; i++)        
    {
        if (a[0] == b[i] && nb - i >= na)  
        {                                   
            Start = i;            
            flag = 1;
            for (j = 0; j < na; j++)
            {
                if (a[j] != b[Start++])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                dem++;
            }
        }
    }
    return dem;
}
int main()
{
    int na, nb;
    int a[MAX], b[MAX];

    cout << ("\nNhap mang a:");
    nhap(a, na);
    xuat(a, na);

    cout << ("\nNhap mang b:");
    nhap(b, nb);
    xuat(b, nb);


    int dem = DemSoLanXuatHienCuaMangATrongMangB(a, b, na, nb);
    cout << "\nSo lan xuat hien cua mang a trong mang b = " << dem;
    return 0;
}