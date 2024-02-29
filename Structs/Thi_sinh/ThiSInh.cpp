#include <iostream>

using namespace std;

struct ThiSinh
{
    char MaThiSinh[6];
    char HoTen[31];
    float DiemToan, DiemLy, DiemHoa;
    float DiemTong;
};

typedef struct ThiSinh THISINH;

void NhapThiSinh (THISINH &a)
{
    fflush(stdin);
    cout << "Nhap ma thi sinh: \n";
    gets(a.MaThiSinh);
    cout << "\n";

    fflush(stdin);
	cout << "Nhap ten thi sinh: \n";
    gets(a.HoTen);
    cout << "\n";

    cout << "Nhap diem toan: \n";
    cin >> a.DiemToan;
    cout << "\n";

    cout << "Nhap diem ly: \n";
    cin >> a.DiemLy;
    cout << "\n";

    cout << "Nhap diem hoa: \n";
    cin >> a.DiemHoa;
    cout << "\n";
}

float TinhDiemTong (THISINH a)
{
    return a.DiemToan + a.DiemLy + a.DiemHoa;
}

void XuatThiSinh (THISINH a)
{
    cout << "Ma thi sinh: \n" << a.MaThiSinh;
    cout << "\n\n";
    cout << "Ten thi sinh: \n" << a.HoTen;
    cout << "\n\n";

    cout << "Diem toan: \n" << a.DiemToan;
    cout << "\n\n";
    cout << "Diem ly: \n" << a.DiemLy;
    cout << "\n\n";
    cout << "Diem hoa: \n" << a.DiemHoa;
    cout << "\n\n";

    cout << "Diem tong: " << TinhDiemTong(a); 
}

int main()
{
    THISINH a;
    NhapThiSinh (a);
    XuatThiSinh (a);

    return 0;
}
