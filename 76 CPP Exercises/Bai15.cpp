#include<iostream>

using namespace std;

int main() {
    int n;
    
    cout << "Nhap n: ";
    cin >> n;
    
    float sum = 0, mau = 0;
    
    for (float i = 1; i <= n; ++i) {
       mau += i;
       sum += 1 / mau;
    }
    
    cout << sum;
    
    return 0;
}