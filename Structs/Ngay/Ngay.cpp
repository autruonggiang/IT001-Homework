#include <iostream>

using namespace std;

const int minYear = 1900, maxYear = 10000;
struct Ngay // Bai 593
{
       int Day, Month, Year;
};
typedef struct Ngay NGAY;

void NhapNgay (NGAY &); // Bai 594
void XuatNgay (NGAY); // Bai 595

bool KiemTraNamNhuan (NGAY); // Bai 596

int TinhSoThuTuNgayTrongNam (NGAY); // Bai 597
int TinhSoThuTuNgayTuNgayChoTruoc (NGAY); // Bai 598

int TimNgayKhiBietNamVaSoThuTuNgayTrongNam (int, int); // Bai 599
int TimNgayKhiBietSoThuTuNgayChoTruoc (int); // Bai 600

NGAY TimNgayKeTiep (NGAY); // Bai 601
NGAY TimNgayHomQua (NGAY); // Bai 602

NGAY TimNgayKeDoKNgay (NGAY, int); // Bai 603
NGAY TimNgayTruocDoKNgay (NGAY, int); // Bai 604

int TimKhoangCach2Ngay (NGAY); // Bai 605
int SoSanh2Ngay (NGAY); // Bai 606

void TinhThuTrongTuanCua1NgayBatKyTrongNam (NGAY);

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
    } while (a.Year < minYear || a.Year > maxYear);

    do
    {
        cout << "\nNhap vao thang: ";
        cin >> a.Month;
        if (a.Month < 1 || a.Month > 12)
        	cout << "\nDu lieu thang khong hop le. Hay kiem tra lai !";
    } while (a.Month < 1 || a.Month > 12);

    int NgayTrongThang = TimSoNgayTrongThang (a);
    do
    {
        cout << "\nNhap vao ngay: ";
        cin >> a.Day;
        if (a.Day < 1 || a.Day > NgayTrongThang)
        {
            cout << "\nDu lieu ngay khong hop le. Hay kiem tra lai !";
        }
    } while (a.Day < 1 || a.Day > NgayTrongThang);
}

void XuatNgay (NGAY ng)
{
	cout << "\nNgay, thang, nam thu duoc: " << endl;
    cout << ng.Day << "/" << ng.Month << "/" << ng.Year << endl;
}

int TinhSoThuTuNgayTrongNam (NGAY a)
{
    int S = a.Day;
    for (int i = 1; i < a.Month; i++) 
    { 
        switch (i)
        {
            case 4: case 6: case 9 : case 11: S += 30; break;
            case 2: S += (a.Year % 4 == 0 && a.Year % 100 != 0 || a.Year % 400 == 0) ? 29 : 28;
                break;
        default: S += 31;
        }
    }
    return S;
}

int TinhSoThuTuNgayTuNgayChoTruoc (NGAY a)
{
    int stt = 0;
    for (int i = 1; i < a.Year; i++)
    {
        if (KiemTraNamNhuan (i))
        {
            stt += 366;
        }
        else
        {
            stt += 365;
        }
    }
    return stt + TinhSoThuTuNgayTrongNam(a);
}

int TimNgayKhiBietNamVaSoThuTuNgayTrongNam (int Year, int STT)
{
    int n[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (KiemTraNamNhuan (Year))
        n[1] = 29;
    for (int i = 0; i < 12; i++)
    {
        if (n[i] < STT)
            STT -= n[i];
        else
            break;
    }
    return STT;
}

int TimNgayKhiBietSoThuTuNgayChoTruoc(int STT)
{
    int Year = 1;
    while (1)
    {
        if (KiemTraNamNhuan (Year))
        {
            if (STT > 366)
            {
                STT -= 366;
            }
            else
            {
                return TimNgayKhiBietNamVaSoThuTuNgayTrongNam (Year, STT);
            }
        }
        else
        {
            if (STT > 365)
            {
                STT -= 365;
            }
            else
            {
                return TimNgayKhiBietNamVaSoThuTuNgayTrongNam (Year, STT);
            }
        }
        Year++;
    }
    return -1;
}

NGAY TimNgayKeTiep (NGAY a)
{
    int NgayTrongThang = TimSoNgayTrongThang (a);
    if (a.Day < NgayTrongThang)  
    {
        a.Day++;
    }
    else if (a.Month < 12)     
    {
        a.Day = 1; a.Month++;
    }
    else                      
    {
        a.Day = a.Month = 1;
        a.Year++;
    }
    return a;
}

NGAY TimNgayHomQua (NGAY a)
{
    int NgayTrongThang = TimSoNgayTrongThang (a);
    if (a.Day == 1)            
    {
        a.Day = NgayTrongThang;        
        if (a.Month == 1)            
        {
            a.Month = 12;
            a.Year--;
        }
        else                     
            a.Month--;
    }
    else                
        a.Day--;
    return a;
}

NGAY TimNgayKeDoKNgay (NGAY a, int k)
{
    while (k > 0)
    {
        a = TimNgayKeTiep (a);
        k--;
    }
    return a;
}

NGAY TimNgayTruocDoKNgay (NGAY a, int k)
{
    while (k>0)
    {
        a = TimNgayHomQua (a);
        k--;
    }
    return a;
}

int TimKhoangCach2Ngay (NGAY a, NGAY b)
{
    int STTa = TinhSoThuTuNgayTrongNam (a);
    int STTb = TinhSoThuTuNgayTrongNam (b);

    if (STTa > STTb)
    {
        return STTa - STTb;
    }
    return STTb - STTa;
}

int SoSanh2Ngay (NGAY a, NGAY b)
{
    int STTa = TinhSoThuTuNgayTrongNam (a);
    int STTb = TinhSoThuTuNgayTrongNam (b);

    if (STTa > STTb)
    {
        return 1;
    }
    if (STTb > STTa)
    {
        return 0;
    }
    return -1;
}

void TinhThuTrongTuanCua1NgayBatKyTrongNam (NGAY a)
{
    a.Year -= (14 - a.Month) / 12;
    a.Month += 12 * ((14 - a.Month) / 12) - 2;

    int dayofweek = (a.Day + a.Year + a.Year / 4 - a.Year / 100 + a.Year / 400 + (31 * a.Month)/12) % 7;

    if (!dayofweek)
        cout << "\nChu nhat !";
    else 
        cout << "\nThu " << dayofweek + 1 <<".";
}

int main ()
{
    NGAY a, b;
    NhapNgay (a);
    XuatNgay (a);

    if (KiemTraNamNhuan (a))
    {
        cout << "\nNam " << a.Year << " la nam nhuan." << endl;
    }
    else
    {
        cout << "\nNam " << a.Year << " la nam thuong." << endl;
    }

    int STTNgay = TinhSoThuTuNgayTrongNam (a);
    cout << "\nNgay thu " << STTNgay << " trong nam." << endl;

    int STT = TinhSoThuTuNgayTuNgayChoTruoc (a);
    cout << "\nNgay thu " << STT << " trong nam tu ngay 1/1/1." << endl;

    int Ngay = TimNgayKhiBietNamVaSoThuTuNgayTrongNam (2015, 365);
    cout << "\nNgay thu " << 365 << " trong nam " << 2015 << " la ngay " << Ngay << "." << endl;

    NGAY c = TimNgayKeTiep (a);
    cout << "\nNgay ke tiep la ngay " << c.Day << "/" << c.Month << "/" << c.Year << "." << endl;

    NGAY d = TimNgayHomQua(a);
    cout << "\nNgay hom qua la ngay " << d.Day << "/" << d.Month << "/" << d.Year << "." << endl;

    cout << "\nNgay ke tiep 5 ngay: ";
    XuatNgay (TimNgayKeDoKNgay (a, 5));
    cout << "\nNgay hom truoc 5 ngay: ";
    XuatNgay (TimNgayTruocDoKNgay (a, 5));

    TinhThuTrongTuanCua1NgayBatKyTrongNam (a);

    return 0;
}
