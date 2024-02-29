#include <iostream>

using namespace std;

const int minYear = 1900, maxYear = 10000;
struct Ngay
{
       int Day, Month, Year;
};

typedef Ngay NGAY;

struct DaiLy // Bai 620
{
    char MaDaiLy[6];
    char TenDaiLy[31];
    int SDT;
    NGAY NgayTiepNhan;
    char DiaChi[51];
    char Email[51];
};

typedef struct DaiLy DAILY;

bool KiemTraNamNhuan (NGAY a)
{
    return (a.Year % 4 == 0 && a.Year % 100 != 0) || (a.Year % 400 == 0);
}

bool KiemTraNamNhuan (int i)
{
    if (i % 4 == 0 && i % 100!=0)
        return true;
    if (i % 400 == 0)
        return true;
    return false;
}

int TimSoNgayTrongThang (NGAY a)
{
    int NgayTrongThang;
    switch (a.Month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        NgayTrongThang = 31;
        break;
    case 4: case 6: case 9 : case 11:
        NgayTrongThang = 30;
        break;
    case 2:
        int Check = KiemTraNamNhuan (a);
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

void NhapNgay (NGAY &a)
{
    do
    {
        cout << "\nNhap vao nam: ";
        cin >> a.Year;
        if (a.Year < minYear || a.Year > maxYear)
        {
            cout << "\nDu lieu nam khong hop le. Hay kiem tra lai !";
        }
    }
	while (a.Year < minYear || a.Year > maxYear);

    do
    {
        cout << "\nNhap vao thang: ";
        cin >> a.Month;
        if (a.Month < 1 || a.Month > 12)
        	cout << "\nDu lieu thang khong hop le. Hay kiem tra lai !";
    }
	while (a.Month < 1 || a.Month > 12);

    int NgayTrongThang = TimSoNgayTrongThang (a);
    do
    {
        cout << "\nNhap vao ngay: ";
        cin >> a.Day;
        if (a.Day < 1 || a.Day > NgayTrongThang)
        {
            cout << "\nDu lieu ngay khong hop le. Hay kiem tra lai !";
        }
    }
	while (a.Day < 1 || a.Day > NgayTrongThang);
}


void XuatNgay (NGAY ng)
{
    cout << ng.Day << "/" << ng.Month << "/" << ng.Year;
}

void NhapDaiLy (DAILY &a)
{
    fflush(stdin);
    cout << "\nNhap ma dai ly: ";
    gets(a.MaDaiLy);

    fflush(stdin);
    cout << "\nNhap ten dai ly: ";
    gets(a.TenDaiLy);

    cout << "\nNhap so dien thoai: ";
    cin >> a.SDT;

    cout << "\nNhap ngay tiep nhan: ";
    NhapNgay (a.NgayTiepNhan);

    fflush(stdin);
    cout << "\nNhap dia chi: ";
    gets(a.DiaChi);

    fflush(stdin);
    cout << "\nNhap email: ";
    gets(a.Email);
}

void XuatDaiLy(DAILY a)
{
    cout << "\nMa dai ly: " << a.MaDaiLy;
    cout << "\nTen dai ly: " << a.TenDaiLy;
    cout << "\nSo dien thoai: ", a.SDT;
    cout << "\nNgay tiep nhan: ";
    XuatNgay(a.NgayTiepNhan);
    cout << "\nDia chi: " << a.DiaChi;
    cout << "\nEmail: " << a.Email;

}

int main()
{
    DAILY a;
    NhapDaiLy (a);
    XuatDaiLy (a);

    return 0;
}
