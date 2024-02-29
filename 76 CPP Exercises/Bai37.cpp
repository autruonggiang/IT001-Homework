#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, i;
    float sum;
    
    cout << "Nhap so nguyen duong n>=2: ";
    cin >> n;
    
    while (n < 2) {
        cout << "Nhap lai so nguyen duong n: ";
        cin >> n;
    }
    
    sum = 0; 
    
    for (float i = 2; i <= n; i++) {
        sum = pow(sum + i, 1 / i);
    }
    
    cout << "Tong cua phep tinh la: " << sum;
    
    return 0;
}
