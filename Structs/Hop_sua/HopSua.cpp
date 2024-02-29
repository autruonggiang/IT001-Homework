#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct NGAY
{
    int day;
    int month;
    int year;
};

struct HOPSUA
{
    char TenNhanHieu[20];
    float TrongLuong;
    NGAY HSD;
};
typedef struct HOPSUA HSUA;

void NhapHopSua (HSUA &a, NGAY &b)
{
    fflush(stdin);
    cout<<"Nhap nhan hieu sua: ";
    gets(a.TenNhanHieu);

    fflush(stdin);
    cout<<"Nhap trong luong hop sua: ";
    cin>>a.TrongLuong;

    fflush(stdin);
    cout<<"Nhap ngay het HSD hop sua: ";
    cin>>b.day;
    cout<<"Nhap thang het HSD hop sua: ";
    cin>>b.month;
    cout<<"Nhap nam het HSD hop sua: ";
    cin>>b.year;

    cout<<"-----------------------------";
    cout<<endl;
}

void XuatHopSua (HSUA a, NGAY b)
{
    cout<<"THONG TIN HOP SUA VUA NHAP"<<endl;
    cout<<"Nhan hieu cua hop sua la: "<<a.TenNhanHieu;
    cout<<endl;
    cout<<"Trong luong cua hop sua: "<<a.TrongLuong<<" N";
    cout<<endl;
    cout<<"Han su dung cua sua: "<<b.day<<"/"<<b.month<<"/"<<b.year;
    cout<<endl;

}

int main()
{
    HSUA a;
    NGAY b;
    NhapHopSua(a,b);
    XuatHopSua(a,b);

    return 0;
}

