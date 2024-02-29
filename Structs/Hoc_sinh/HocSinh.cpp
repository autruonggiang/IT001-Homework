#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct HOCSINH
{
    char TenHS[30];
    int DToan;
    int DVan;
    float DTB;
};

typedef struct HOCSINH HS;

void NhapHocSinh (HS &a)
{
    fflush(stdin);
    cout<<"Nhap ten cua hoc sinh: ";
    gets(a.TenHS);

    fflush(stdin);
    cout<<"Nhap diem toan: ";
    cin>>a.DToan;

    fflush(stdin);
    cout<<"Nhap diem van: ";
    cin>>a.DVan;

    fflush(stdin);
    a.DTB = (float)(a.DToan+a.DVan)/2;
    cout<<"---------------------------";
    cout<<endl;
}

void XuatHocSinh (HS a)
{
    cout<<"BANG DIEM CUA HOC SINH"<<endl;
    cout<<"Ten hoc sinh: "<<a.TenHS<<endl;
    cout<<"Diem toan: "<<a.DToan<<endl;
    cout<<"Diem van: "<<a.DVan<<endl;
    cout<<"Diem trung binh cua hoc sinh: "<<a.DTB<<endl;
}

int main()
{
    HS a;
    NhapHocSinh(a);
    XuatHocSinh(a);
}
