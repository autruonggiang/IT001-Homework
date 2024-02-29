#include <iostream>

using namespace std;

const int minYear = 1900, maxYear = 10000;

struct Gio 
{
    int Hour, Minute, Second;
};

typedef struct Gio GIO;

struct Ngay
{
    int Day, Month, Year;
};

typedef struct Ngay NGAY;

struct Ve // Bai 609
{
    char TenPhim[20];
    long GiaTien;
    NGAY NgayChieu;
};

typedef struct Ve VE;

bool KiemTraNamNhuan (NGAY a)
{
    return (a.Year % 4 == 0 && a.Year % 100 != 0) || (a.Year % 400 == 0);
}

bool KiemTraNamNhuan (int i)
{
    if (i % 4 == 0 && i % 100 != 0)
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

void NhapGio (GIO &g)
{
        cout << "\nNhap gio: ";
        cin >> g.Hour;

    	cout << "\nNhap phut: ";
        cin >> g.Minute;
    
        cout << "\nNhap giay: ";
        cin >> g.Second;
}

void XuatGio (GIO g)
{
    cout << g.Hour << ":" << g.Minute << ":" << g.Second;
}

void NhapNgay(NGAY &a)
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


void XuatNgay(NGAY ng)
{
    cout << ng.Day << "/" << ng.Month << "/" << ng.Year;
}

void NhapVe(VE &ve)
{
    

    fflush(stdin);
    cout << "\nNhap vao ten phim: ";
    gets(ve.TenPhim);

    do 
    {
        cout << "\nNhap vao gia ve: ";
        cin >> ve.GiaTien;

        if (ve.GiaTien < 0)
        {
            cout << "\nGia ve khong hop le. Hay kiem tra lai !";
        }

    } while (ve.GiaTien < 0);


    cout << "\nNhap ngay chieu: ";
    NhapNgay (ve.NgayChieu);
}

void XuatVe(VE ve)
{
    
    cout << "\nTen phim: " << ve.TenPhim;
    cout << "\nGia ban: " << ve.GiaTien;
    cout << "\nNgay chieu: ";
    XuatNgay (ve.NgayChieu);
    
}

int main()
{
    VE v;
    NhapVe(v);
    XuatVe(v);
    
    return 0;
}
