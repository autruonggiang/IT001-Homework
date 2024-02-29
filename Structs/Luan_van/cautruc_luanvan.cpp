#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct  LuanVan
{
    char MaLuanVan[10], TenLuanVan[100], TenSinhVien[30], TenGiangVienHD[30];
    int NamThucHien;
};
typedef struct LuanVan LUANVAN;

void NhapLuanVan(LUANVAN& lv)
{
    fflush(stdin);
    cout << "Nhap ma luan van : ";
    cin >> lv.MaLuanVan;

    fflush(stdin);
    cout << "Nhap ten luan van : ";
    cin >> lv.TenLuanVan;

    fflush(stdin);
    cout << "Nhap ten sinh vien thuc hien : ";
    cin >> lv.TenSinhVien;

    fflush(stdin);
    cout << "Nhap ten giang vien huong dan : ";
    cin >> lv.TenGiangVienHD;

    cout << "Nhap nam thuc hien : ";
    cin >> lv.NamThucHien;

}
void XuatLuanVan(LUANVAN lv)
{
    cout << "Ma luan van : " << lv.MaLuanVan << endl;
    cout << "Ten luan van : " << lv.TenLuanVan << endl;
    cout << "Ten sinh vien thuc hien : " << lv.TenLuanVan << endl;
    cout << "Ten giang vien huong dan : " << lv.TenGiangVienHD << endl;
    cout << "Nam thuc hien : " << lv.NamThucHien << endl;
}

int main()
{
    LUANVAN a;
    NhapLuanVan(a);
    XuatLuanVan(a);

    return 0;
}