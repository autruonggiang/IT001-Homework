#include<stdio.h>
#include<conio.h>
#include<iostream>
const int minYear = 1900, maxYear = 10000;
using namespace std;
struct Ngay
{
    int Day, Month, Year;
};
typedef Ngay NGAY;

struct SoTietKiem
{
    char MaSo[5];
    char LoaiTietKiem[10];
    char TenKhachHang[30];
    int CMND;
    NGAY NgayMoSo;
    float SoTienGui;
};
typedef struct SoTietKiem SOTIETKIEM;

bool KiemTraNamNhuan(NGAY a)
{
    return (a.Year % 4 == 0 && a.Year % 100 != 0) || (a.Year % 400 == 0);
}

bool KiemTraNamNhuan(int i)
{
    if (i % 4 == 0 && i % 100 != 0)
        return true;
    if (i % 400 == 0)
        return true;
    return false;
}
int TimSoNgayTrongThang(NGAY a)
{
    int NgayTrongThang;
    switch (a.Month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        NgayTrongThang = 31;
        break;
    case 4: case 6: case 9: case 11:
        NgayTrongThang = 30;
        break;
    case 2:
        int Check = KiemTraNamNhuan(a);
        if (Check == 1)
        {
            NgayTrongThang = 29;
        }
        else
        {
            NgayTrongThang = 28;
        }
    }
    return NgayTrongThang;
}
void NhapNgay(NGAY& a)
{
    do
    {
        cout << "Nhap vao nam: ";
        cin >> a.Year;
        if (a.Year < minYear || a.Year > maxYear)
        {
            cout << "Du lieu nam khong hop le. Xin kiem tra lai!";
        }
    } while (a.Year < minYear || a.Year > maxYear);

    do
    {
        cout << "Nhap vao thang: ";
        cin >> a.Month;
        if (a.Month < 1 || a.Month > 12)
            cout << "Du lieu thang khong hop le.Xin kiem tra lai!";
    } while (a.Month < 1 || a.Month > 12);

    int NgayTrongThang = TimSoNgayTrongThang(a);
    do
    {
        cout << "Nhap vao ngay : ";
        cin >> a.Day;
        if (a.Day < 1 || a.Day > NgayTrongThang)
        {
            cout << "Du lieu ngay khong hop le. Xin kiem tra lai!";
        }
    } while (a.Day < 1 || a.Day > NgayTrongThang);
}


void XuatNgay(NGAY ng)
{
    cout << ng.Day;
    cout << ng.Month;
    cout << ng.Year;
}

void NhapSoTietKiem(SOTIETKIEM& a)
{
    fflush(stdin);
    cout << "Nhap ma so: ";
    cin >> a.MaSo;

    fflush(stdin);
    cout << "Nhap loai tiet kiem : ";
    cin >> a.LoaiTietKiem;

    fflush(stdin);
    cout << "Nhap ho ten khach hang : ";
    cin >> a.TenKhachHang;

    cout << "Nhap CMND : ";
    cin >> a.CMND;

    cout << "Nhap ngay mo so : ";
    NhapNgay(a.NgayMoSo);

    cout << "Nhap so tien gui : ";
    cin >> a.SoTienGui;
}

void XuatSoTietKiem(SOTIETKIEM a)
{
    cout << endl;
    cout << "Ma so : " << a.MaSo;
    cout << endl;
    cout << "Loai tiet kiem : " << a.LoaiTietKiem;
    cout << endl;
    cout << "Ten khach hang : " << a.TenKhachHang;
    cout << endl;
    cout << "CMND: " << a.CMND;
    cout << endl;
    cout << "Ngay mo so : ";
    XuatNgay(a.NgayMoSo);
    cout << endl;
    cout << "So tien gui : " << a.SoTienGui << " (VND)";
}

int main()
{
    SOTIETKIEM a;
    NhapSoTietKiem(a);
    XuatSoTietKiem(a);

    return 0;
}