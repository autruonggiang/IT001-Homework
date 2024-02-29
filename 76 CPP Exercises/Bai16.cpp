#include<iostream>

using namespace std;

int main() {
    int x, n;
    
    cin >> x >> n;
    
    float multi = 1, mau = 0;
    
    float sum = 0;
    
    for (float i = 1; i<= n; ++i) {
        multi *= x;
        mau += i;
        
        sum += multi / mau;
    }

    cout << sum;
    
    return 0;
}