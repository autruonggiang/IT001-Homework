#include <iostream>

using namespace std;

int main()
{
    long N,tempN;
    float first;
    
    cout << "Nhap so nguyen duong n: ";
    cin >> N;
    
    while ( N < 0 ) {
        cout<<"N khong hop le, moi thu so khac: ";
        cin >> N;
    }
    
    tempN = N;
    
    do {
        first= tempN % 10;
    }
    
    while (tempN /= 10);
    
    cout << "Chu so dau tien cua " << N << " la: " << first;
    
    return 0;
}
