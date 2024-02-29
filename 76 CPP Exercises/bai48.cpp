#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long n, tempN;
    int Tich = 1;
    
    do
    {
        cout << "Hay nhap vao so nguyen duong n: ";
        cin >> n;
    } 
	
	while (n < 0 && cout << "N khong hop le, moi nhap lai!");
	
    tempN = n;
    
    while (tempN != 0) {
        if (tempN % 2 != 0) {
            Tich = Tich * (tempN % 10);
        }
        
        tempN = tempN / 10;
    }
    
    cout << "Tich cac so le cua " << n << " la: " << Tich;

    return 0;
}