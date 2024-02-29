#include <iostream>

using namespace std;

bool KiemTra_SoGiamDan (int N)
{
    int tMin = N % 10;
    
    N = N / 10;

    while (N > 0)
    {
        int t = N % 10;

        if (t <= tMin)
            return false;
            
        else
            tMin = t;

        N = N / 10;
    }
    
    return true;
}

int main ()
{
    int N;
    
    cout << "Nhap N: ";
    cin >> N;

    bool result = KiemTra_SoGiamDan (N);
    
    if (result)
        cout << "Day la so giam dan !";
        
    else
        cout << "Khong phai la so giam dan !" << endl;
        
    return 0;
}
