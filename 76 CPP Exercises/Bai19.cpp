#include<iostream>

using namespace std;

int gt(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } 
	
	else {
        return n * gt(n - 1);
    }
    
}

int main() {
    int x, n;
    
    cin >> x >> n;
    
    float multi = x, mau;
    float sum = 1;
    for (float i = 0; i<= n; ++i) {
        mau = gt(2 * i + 1);
        sum += multi / mau;
        
        multi *= x * x;
    }

    cout << sum;
    
    return 0;
}