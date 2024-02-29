#include<iostream>

using namespace std;

int main() {
    int n;
    
    cout << "Nhap S(n): ";
    cin >> n;
    
    int tu = 1;
    float sum = 1, mau;
    
    for (int i = 1; i <= n; ++i) {
        mau = 1 + sum;
        sum = (float) tu / mau;
    }
    
    cout << "S(" << n << "): " << sum;
    
    return 0;
}