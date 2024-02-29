#include<iostream>

using namespace std;

unsigned long long int gt(unsigned long long int n) {
    if (n == 1 || n == 0) {
        return 1;
    } 
	
	else {
        return n * gt(n - 1);
    }
}

int main() {
    unsigned long long int x, n;
    
    cout << "S(x, n): ";
    cin >> x >> n;
    
    unsigned long long int multi = 1, mau;
    float sum = 0;
    
    for (float i = 0; i<= n; ++i) {
        mau = gt(2 * i);
        sum += (multi * 1.0f) / (mau * 1.0f);
        
        multi *= x * x;
    }

    cout << "S(" << x << ", " << n << "): " << sum;
    
    return 0;
}