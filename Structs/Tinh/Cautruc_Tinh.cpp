#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct Tinh
{
    int MaTinh;
    char TenTinh[30];
    float DienTich;
    long DanSo;
};
typedef struct Tinh TINH;

void NhapTinh(TINH& t)
{
    cout << "Nhap ma tinh: \n";
    cin >> t.MaTinh;

    fflush(stdin);
    cout << "Nhap vao ten tinh: \n";
    cin >> t.TenTinh;

    cout << "Nhap vao dien tich: \n";
    cin >> t.DienTich;

    cout << "Nhap vao Dan so: \n";
    cin >> t.DanSo;
}

void XuatTinh(TINH t)
{
    cout << endl;
    cout << "Ma tinh: " << t.MaTinh << endl;
    cout << "Ten tinh: " << t.TenTinh << endl;
    cout << "Dien tich: " << t.DienTich << " (km ^ 2)" << endl;
    cout << "Dan so: " << t.DanSo << " Nguoi ";
}

int main()
{
    TINH t1;
    NhapTinh(t1);
    XuatTinh(t1);

    return 0;
}