#include <iostream>
#include <string.h>

#define MAX 50

using namespace std;

struct HocSinh
{
    char HoTen[30];
    int DiemToan, DiemVan;
    float DiemTB;
};

typedef struct HocSinh HOCSINH;

struct LopHoc
{
    char TenLop[30];
    int SiSo;
    HOCSINH DanhSachHocSinh[MAX];
};


typedef struct LopHoc LOPHOC;

void NhapHocSinh (HOCSINH &a)
{

    fflush(stdin);
    cout << "\nNhap ten hoc sinh: ";
    gets(a.HoTen);
    cout << "\n";

    cout << "Nhap diem toan: ";
    cin >> a.DiemToan;
    cout << "\n";

	cout << "Nhap diem van: ";
    cin >> a.DiemVan;
    cout << "\n";
}

float TinhDiemTB (HOCSINH a)
{
    return (float) (a.DiemToan + a.DiemVan) / 2;
}

void XuatHocSinh (HOCSINH a)
{
    cout << "Ten hoc sinh: " << a.HoTen;
    cout << "\n";
    cout << "Diem toan: " << a.DiemToan;
    cout << "\n";
    cout << "Diem van: " << a.DiemVan;
    cout << "\n";
    cout << "Diem trung binh: " << TinhDiemTB(a); 
}

void NhapLopHoc (LOPHOC &a)
{
    fflush(stdin);
    cout << "Nhap ten lop: ";
	cin >> a.TenLop;
    gets(a.TenLop);

    do
    {
        cout << "Nhap si so: \n";
        cin >> a.SiSo;
        if (a.SiSo < 0 || a.SiSo > MAX)
        {
            cout << "\nSo luong khong hop le. Hay kiem tra lai !";
        }
    }
	while (a.SiSo < 0 || a.SiSo > MAX);

    for (int i = 0; i < a.SiSo; i++)
    {
        cout << "\nNhap vao hoc sinh thu " << i + 1;
        NhapHocSinh (a.DanhSachHocSinh[i]);
    }
}

void XuatLopHoc( LOPHOC a)
{
    for (int i = 0; i < a.SiSo; i++)
    {
        cout << "\nXuat ra hoc sinh thu " << i + 1;
        cout << "\n";
        XuatHocSinh (a.DanhSachHocSinh[i]);
    }
}

int main()
{
    LOPHOC a;
    NhapLopHoc (a);
    XuatLopHoc (a);

    return 0;
}
