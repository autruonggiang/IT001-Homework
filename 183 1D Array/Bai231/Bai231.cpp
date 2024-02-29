#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAX 100
using namespace std;
void nhap(int a[], int& n)
{
    do
    {
        cout << "Nhap so phan tu : ";
        cin >> n;
        if (n <= 0 || n > MAX)
        {
            cout << "So phan tu khong hop le.Xin kiem tra lai !";
        }
    } while (n <= 0 || n > MAX);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i <<"]: ";
        cin >> a[i];
    }
}


void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int KiemTraBiTrung(int a[], int n, int ViTri)
{
    for (int i = ViTri - 1; i >= 0; i--)
    {
        if (a[i] == a[ViTri])
        {
            return 0; 
        }
    }
    return 1;       
}

int DemSoLuongPhanTuTrung(int a[], int n, int ViTri)
{
    int dem = 1;
    for (int i = ViTri + 1; i < n; i++)
    {
        if (a[i] == a[ViTri])
        {
            dem++;
        }
    }
    return dem;
}

void LietKeCacGiaTriXuatHienDung1Lan(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int CheckTrung = KiemTraBiTrung(a, n, i);
        if (CheckTrung == 1)
        {
            int dem = DemSoLuongPhanTuTrung(a, n, i);
            if (dem == 1)
            {
                cout << "Cac phan tu xuat hien dung 1 lan la " << a[i] << endl;
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
    LietKeCacGiaTriXuatHienDung1Lan(a, n);

    return 0;
}