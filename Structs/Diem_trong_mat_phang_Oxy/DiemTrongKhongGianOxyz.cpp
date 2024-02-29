#include <iostream>
#include <math.h>

using namespace std;

struct Diem // Bai 555
{
    float X;
    float Y;
    float Z;
};

typedef struct Diem DIEM;

void NhapDiem (DIEM &);
void XuatDiem (DIEM);

float TinhKhoangCachGiua2Diem (DIEM, DIEM);
float TinhKhoangCachGiua2DiemTheoOx (DIEM, DIEM);
float TinhKhoangCachGiua2DiemTheoOy (DIEM, DIEM);
float TinhKhoangCachGiua2DiemTheoOz (DIEM, DIEM);

DIEM TimDiemDoiXungQuaO (DIEM);
DIEM TimDiemDoiXungQuaOxy (DIEM);
DIEM TimDiemDoiXungQuaOxz (DIEM);
DIEM TimDiemDoiXungQuaOyz (DIEM);

void NhapDiem (DIEM &a) // Bai 556
{
    cout << "\nNhap x: ";
    cin >> a.X;
    cout << "\n";

    cout << "\nNhap y: ";
    cin >> a.Y;
    cout << "\n";

    cout << "\nNhap z: ";
    cin >> a.Z;
    cout << "\n";
}

void XuatDiem(DIEM a) // Bai 557
{
    cout << "(" << a.X << ", " << a.Y << ", " << a.Z << ")";
}

float TinhKhoangCachGiua2Diem (DIEM a, DIEM b) // Bai 558
{
    return sqrt (pow((b.X - a.X), 2) + pow((b.Y - a.Y), 2) + pow((b.Z - a.Z), 2));
}

float TinhKhoangCachGiua2DiemTheoOx (DIEM a, DIEM b) //Bai 559
{
    return fabs(a.X - b.X);
}

float TinhKhoangCachGiua2DiemTheoOy (DIEM a, DIEM b) //Bai 560
{
    return fabs(a.Y - b.Y);    
}

float TinhKhoangCachGiua2DiemTheoOz (DIEM a, DIEM b) //Bai 561
{
    return fabs(a.Z - b.Z);
}

DIEM TimDiemDoiXungQuaO (DIEM a) // Bai 562
{
    DIEM c;
    c.X = -1 * a.X;
    c.Y = -1 * a.Y;
    c.Z = -1 * a.Z;
    return c;
}

DIEM TimDiemDoiXungQuaOxy (DIEM a) // Bai 563
{
    DIEM c;
    c.X = 1 * a.X;
    c.Y = 1 * a.Y;
    c.Z = -1 * a.Z;
    return c;
}

DIEM TimDiemDoiXungQuaOxz (DIEM a) // Bai 564
{
    DIEM c;
    c.X = 1 * a.X;
    c.Y = -1 * a.Y;
    c.Z = 1 * a.Z;
    return c;
}

DIEM TimDiemDoiXungQuaOyz (DIEM a) //  Bai 565
{
    DIEM c;
    c.X = -1 * a.X;
    c.Y = 1 * a.Y;
    c.Z = 1 * a.Z;
    return c;
}

int main()
{
    DIEM a, b;
    cout << "\nDiem A: ";
    NhapDiem(a);
    XuatDiem(a);
	cout << "\n";

    cout << "\nDiem B: ";
    NhapDiem(b);
    XuatDiem(b);
	cout << "\n";
	
    float khoangcach = TinhKhoangCachGiua2Diem (a, b);
    cout << "\nKhoang cach giua 2 diem A, B = " << khoangcach;

    float khoangcachOx = TinhKhoangCachGiua2DiemTheoOx (a, b);
    cout << "\nKhoang cach giua 2 diem A,B theo Ox = " << khoangcachOx;

    float khoangcachOy = TinhKhoangCachGiua2DiemTheoOy (a, b);
    cout << "\nKhoang cach giua 2 diem A,B theo Oy = " << khoangcachOy;

    float khoangcachOz = TinhKhoangCachGiua2DiemTheoOz (a, b);
    cout << "\nKhoang cach giua 2 diem A,B theo Oz = " << khoangcachOz;

    DIEM c = TimDiemDoiXungQuaO (a);
    cout << "\nDiem C doi xung diem A qua O: ";
    XuatDiem (c);

    DIEM d = TimDiemDoiXungQuaOxy (b);
    cout << "\nDiem D doi xung diem B qua Oxy: ";
    XuatDiem (d);
    
    DIEM e = TimDiemDoiXungQuaOxz (a);
    cout << "\nDiem E doi xung diem A qua Oxz: ";
    XuatDiem (e);

    DIEM f = TimDiemDoiXungQuaOyz (b);
    cout << "\nDiem F doi xung diem B qua Oyz: ";
    XuatDiem (f);

    return 0;
}
