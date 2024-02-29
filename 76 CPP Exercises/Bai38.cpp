#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    float sum;
    
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    
    sum = 0;
    
    while (n < 0) {
        cout<<"N khong hop le, moi nhap lai: ";
        cin >> n;
    }
    
    for (float i = 1; i <= n; i++) {
        sum = pow(sum + i, 1 / (i + 1));
    }
    
    cout << "Tong cua phep tinh la:" << sum;
    
    return 0;
}
