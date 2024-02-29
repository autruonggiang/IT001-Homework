#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAX 100
using namespace std;
void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao phan tu a[" << i << "]: ";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n)
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

void DemTanSuatXuatHien(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int CheckTrung = KiemTraBiTrung(a, n, i);
        if (CheckTrung == 1)
        {
            int dem = DemSoLuongPhanTuTrung(a, n, i);
            cout << "Phan tu " << n << " xuat hien " << dem << "lan" << endl;
        }
    }
}
int main()
{
    int n;
    do
    {
        cout << "Nhap vao so luong phan tu cua mang : ";
        cin >> n;
        if (n < 0 || n > MAX)
        {
            cout << "So luong phan tu nhap vao khong hop le.Xin kiem tra lai !";
        }
    } while (n < 0 || n > MAX);

    int a[MAX];
    NhapMang(a, n);
    XuatMang(a, n);
    cout << endl;
    DemTanSuatXuatHien(a, n);
    return 0;
}