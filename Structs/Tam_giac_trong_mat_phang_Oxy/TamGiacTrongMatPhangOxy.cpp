#include <iostream>
#include <math.h>

using namespace std;

struct Diem // Bai 581
{
    float x;
    float y;
};

typedef struct Diem DIEM;

void NhapDiem (DIEM &); 
void XuatDiem (DIEM);

float TinhKhoangCachGiua2Diem (DIEM, DIEM);

void NhapDiem(DIEM &a) 
{
    cout << "\nNhap x: ";
    cin >> a.x;

    cout << "\nNhap y: ";
    cin >> a.y;
}

void XuatDiem(DIEM a) 
{
	cout << "(" << a.x << ", " << a.y << ")";
}

float TinhKhoangCachGiua2Diem (DIEM a, DIEM b)
{
    return sqrt (pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

struct TamGiac 
{
    DIEM A;
    DIEM B;
    DIEM C;
};

typedef struct TamGiac TAMGIAC;

void NhapTamGiac (TAMGIAC &);
void XuatTamGiac (TAMGIAC);

bool KiemTraCoPhaiTamGiac (TAMGIAC);
float TinhChuViTamGiac (TAMGIAC);
float TinhDienTichTamGiac (TAMGIAC);

DIEM TimToaDoTrongTamTamGiac (TAMGIAC);

DIEM TimDinhCoHoanhDoLonNhat (TAMGIAC);
DIEM TimDinhCoTungDoNhoNhat (TAMGIAC);

float TinhKhoangCachTuPToi3Dinh (TAMGIAC, DIEM);
bool KiemTra1DiemCoNamTrongTamGiac (TAMGIAC, DIEM);

int ChoBietDangTamGiac (TAMGIAC);

void NhapTamGiac (TAMGIAC &a) // Bai 582
{
    int Check;
    do
	{
        cout << "\nNhap dinh A: ";
        NhapDiem (a.A);

        cout << "\nNhap dinh B: ";
        NhapDiem (a.B);

        cout << "\nNhap dinh C: ";
        NhapDiem (a.C);
        Check = KiemTraCoPhaiTamGiac (a);

        if (Check == false)
        {
            cout << "\n3 diem khong tao thanh tam giac. Hay kiem tra lai !";
        }

    }
	while (Check == false);
}

void XuatTamGiac (TAMGIAC a) // Bai 583
{
    cout << "((" << a.A.x << ", " << a.A.y << ")" << " ; (" << a.B.x << ", " << a.B.y << ")" << " ; (" << a.C.x << ", " << a.C.y << "))";
	cout << "\n";
}

bool KiemTraCoPhaiTamGiac (TAMGIAC a) // Bai 584
{
    float AB = TinhKhoangCachGiua2Diem (a.A, a.B);
    float BC = TinhKhoangCachGiua2Diem (a.B, a.C);
    float AC = TinhKhoangCachGiua2Diem (a.A, a.C);

    if (AB + BC <= AC || AB + AC <= BC || AC + BC <= AB)
        return false;
    return true;
}

float TinhChuViTamGiac (TAMGIAC a) // Bai 585
{
    float AB = TinhKhoangCachGiua2Diem (a.A, a.B);
    float BC = TinhKhoangCachGiua2Diem (a.B, a.C);
    float AC = TinhKhoangCachGiua2Diem (a.A, a.C);

    return AB + BC + AC;
}

float TinhDienTichTamGiac (TAMGIAC a) // Bai 586
{
    float AB = TinhKhoangCachGiua2Diem (a.A, a.B);
    float BC = TinhKhoangCachGiua2Diem (a.B, a.C);
    float AC = TinhKhoangCachGiua2Diem (a.A, a.C);
    float P = TinhChuViTamGiac (a) / 2;

    return sqrt (P * (P - AB) * (P - AC) * (P - BC));
}

DIEM TimToaDoTrongTamTamGiac (TAMGIAC a) // Bai 587
{
    DIEM G;
    G.x = (a.A.x + a.B.x + a.C.x) / 3;
    G.y = (a.A.y + a.B.y + a.C.y) / 3;

    return G;
}

DIEM TimDinhCoHoanhDoLonNhat (TAMGIAC a) // Bai 588
{
    DIEM I;
    I.x = a.A.x > a.B.x ? a.A.x : a.B.x;
    I.x = I.x > a.C.x ? I.x : a.C.x;

    if (I.x == a.A.x)
        I.y = a.A.y;
    else if (I.x == a.B.x)
        I.y = a.B.y;
    else if (I.x = a.C.x)
        I.y = a.C.y;
    return I;
}

DIEM TimDinhCoTungDoNhoNhat (TAMGIAC a) // Bai 589
{
    DIEM J;
    J.y = a.A.y < a.B.y ? a.A.y : a.B.y;
    J.y = J.y < a.C.y ? J.y : a.C.y;

    if (J.y == a.A.y)
        J.x = a.A.x;
    else if (J.y = a.B.y)
        J.x = a.B.x;
    else if (J.y = a.C.y)
        J.x = a.C.x;
    return J;
}

float TinhKhoangCachTuPToi3Dinh (TAMGIAC a, DIEM P) // Bai 590
{
    float PA = TinhKhoangCachGiua2Diem (a.A, P);
    float PB = TinhKhoangCachGiua2Diem (a.B, P);
    float PC = TinhKhoangCachGiua2Diem (a.C, P);
    return PA + PB + PC;
}


float XetViTriTuongDoiGiuaDiemVaDuongThang (DIEM d1, DIEM d2, DIEM d3)
{
    return (d1.x - d3.x) * (d2.y - d3.y) - (d2.x - d3.x) * (d1.y - d3.y);
}

bool KiemTra1DiemCoNamTrongTamGiac (TAMGIAC a, DIEM D) // Bai 591
{
    DIEM v1 = a.A;
    DIEM v2 = a.B;
    DIEM v3 = a.C;
    bool b1, b2, b3;

    b1 = XetViTriTuongDoiGiuaDiemVaDuongThang (D, v1, v2) < 0.0f;
    b2 = XetViTriTuongDoiGiuaDiemVaDuongThang (D, v2, v3) < 0.0f;
    b3 = XetViTriTuongDoiGiuaDiemVaDuongThang (D, v3, v1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

int ChoBietDangTamGiac (TAMGIAC a) // Bai 592
{
    float AB = TinhKhoangCachGiua2Diem (a.A, a.B);
    float BC = TinhKhoangCachGiua2Diem (a.B, a.C);
    float AC = TinhKhoangCachGiua2Diem (a.A, a.C);

    int flag;
    if (AB == BC && AC == BC)
    {
        flag = 1; // Deu
    }
    else 
    {
        if (AB * AB + BC * BC == AC * AC || AC * AC + BC * BC == AB * AB || AB * AB + AC * AC == BC * BC)
        {
            flag = 2;  // Vuong
        }
        if(AB == BC || AC == BC || AB == AC)
        {
            flag = 3;   // Can
        }
        else
        {
            flag = 4;   // Thuong
        }
    }
    return flag;
}

int main()
{
    TAMGIAC a, b;

    NhapTamGiac (a);
    XuatTamGiac (a);

    float ChuVi = TinhChuViTamGiac (a);
    float DienTich = TinhDienTichTamGiac (a);

    DIEM G = TimToaDoTrongTamTamGiac (a);

    cout << "\nChu vi tam giac = " << ChuVi;
	cout << "\nDien tich tam giac = " << DienTich;
    cout << "\nToa do trong tam tam giac la: (" << G.x << ", " << G.y << ")";


    DIEM I = TimDinhCoHoanhDoLonNhat (a);
    cout << "\nDinh co hoanh do lon nhat la: ";
    XuatDiem (I);

    DIEM J = TimDinhCoTungDoNhoNhat (a);
    cout << "\nDinh tung do nho nhat la: ";
    XuatDiem (J);

    float KhoangCach = TinhKhoangCachTuPToi3Dinh (a, G);
    cout << "\nkhoang cach = " << KhoangCach;

    int flag = ChoBietDangTamGiac (a);

    if (flag == 1)
    {
        cout << "\nTam giac deu !";
    }
    else 
    {
        if (flag == 2)
        {
            cout << "\nTam giac vuong !";
        }
        if (flag == 3)
        {
            cout << "\nTam giac can !";
        }
        else 
        {
            cout << "\nTam giac thuong !";
        }
    }
    
    if (KiemTra1DiemCoNamTrongTamGiac (a, G))
    {
        cout << "\nDiem nam trong tam giac !";
    }
    else
    {
        cout << "\nDiem khong nam trong tam giac !";
    }

    return 0;
}
