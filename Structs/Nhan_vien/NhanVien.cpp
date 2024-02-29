#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct NHANVIEN
{
    char MaNV[5];
    char TenNV[30];
    long long int Luong;
};
typedef struct NHANVIEN  NV;

void NhapNhanVien (NV &a)
{
    //fflush(stdin);
    cout<<"Nhap ma nhan vien: "<<endl;
    gets(a.MaNV);

    //fflush(stdin);
    cout<<"Nhap ten nhan vien: "<<endl;
    gets(a.TenNV);

    //fflush(stdin);
    cout<<"Nhap so luong nhan vien nhan duoc: "<<endl;
    cin>>a.Luong;
}

void XuatNhanVien (NV a)
{
    cout<<"Ma nhan vien la: "<<a.MaNV;
    cout<<endl;
    cout<<"Ten nhan vien la: "<<a.TenNV;
    cout<<endl;
    cout<<"So luong nhan vien nhan duoc la: "<<a.Luong<<" VND";
    cout<<endl;

}

int main()
{
    NV a;
    NhapNhanVien(a);
    XuatNhanVien(a);

    return 0;
}
