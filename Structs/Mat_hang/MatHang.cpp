#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct MATHANG
{
    char TenMatHang[20];
    int DonGia;
    int SLTon;
};
typedef struct MATHANG MH;

void NhapMatHang (MH &a)
{
    fflush(stdin);
    cout<<"Nhap ten mat hang: ";
    gets(a.TenMatHang);

    fflush(stdin);
    cout<<"Nhap don gia mat hang: ";
    cin>>a.DonGia;

    fflush(stdin);
    cout<<"Nhap so luong con ton kho: ";
    cin>>a.SLTon;
    cout<<"-------------------------";
    cout<<endl;
}

void XuatMatHang (MH a)
{
    cout<<"THONG TIN MAT HANG VUA NHAP"<<endl;
    cout<<"Ten mat hang la: "<<a.TenMatHang;
    cout<<endl;
    cout<<"Don gia cua mat hang la: "<<a.DonGia;
    cout<<endl;
    cout<<"So luong hang con ton kho la: "<<a.SLTon;
    cout<<endl;

}

int main()
{
    MH a;
    NhapMatHang(a);
    XuatMatHang(a);

    return 0;
}

