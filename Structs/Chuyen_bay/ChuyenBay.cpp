#include <iostream>

using namespace std;

struct Gio 
{
    int Hour, Minute, Second;
};

typedef struct Gio GIO;

struct Ngay
{
       int Day, Month, Year;
};

typedef Ngay NGAY;

struct ChuyenBay 
{
    char Ma[6], NoiDi[21], NoiDen[21];
    Ngay NgayBay;
    Gio GioBay;
};

typedef struct ChuyenBay CHUYENBAY;


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

void NhapNgay (NGAY &ng)
{
    cout << "\nNhap ngay: ";
    cin >> ng.Day;

	cout << "\nNhap thang: ";
    cin >> ng.Month;

    cout << "\nNhap nam: ";
    cin >> ng.Year;
}

void XuatNgay (NGAY ng)
{
    cout << ng.Day << "-" << ng.Month << "-" << ng.Year;
}

void NhapChuyenBay (CHUYENBAY &cb)
{
    fflush(stdin);
    cout << "\nNhap vao ma chuyen bay: ";
    gets(cb.Ma);

    fflush(stdin);
    cout << "\nNhap noi di: ";
    gets(cb.NoiDi);

    fflush(stdin);
    cout << "\nNhap noi den: ";
    gets(cb.NoiDen);

    cout << "\nNhap vao ngay bay: ";
    NhapNgay (cb.NgayBay);

    cout << "\nNhap vao gio bay: ";
    NhapGio (cb.GioBay);

}

void XuatChuyenBay (CHUYENBAY cb)
{
	cout << "\nMa chuyen bay: " << cb.Ma;
    cout << "\nNoi di: " << cb.NoiDi;
    cout << "\nNoi den: " << cb.NoiDen;
    cout << "\nNgay bay: ";
    XuatNgay (cb.NgayBay);
    cout << "\nGio bay: ";
    XuatGio (cb.GioBay);
}

int main()
{
    CHUYENBAY cb;
    NhapChuyenBay (cb);
    XuatChuyenBay (cb);

    return 0;
}
