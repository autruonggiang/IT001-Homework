#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cout << "Moi nhap so n: ";
    cin >> n;
    
    while (n <= 0) {
        cout << "N khong hop le, moi nhap lai: ";
        cin >> n;
    }
    
    
    int re = 0;
    while (n > 0) {
        re = re * 10 + n % 10;
        n = n / 10;
    }
    
    cout << "So dao nguoc la: " << re;
	
	return 0;
}