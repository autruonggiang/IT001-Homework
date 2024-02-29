#include<iostream>
#include<math.h>

using namespace std;

int gt(int n) {
    if ( n == 1 || n == 0)
        return 1;
        
    return n * gt(n - 1);
}

int main() {
    
    int x, n;
    cout << "S(x, n): ";
    cin >> x >> n;
    
    float sum = 0;
    unsigned long long int mau;
    unsigned long long int multi = x;
    float power;
    
    for (float i = 0; i <= n; ++i) {
        if (i != 0)
	        multi *= x * x;
	        mau = gt(2 * i + 1);
	        power = pow(-1, i + 1);
	        
        	sum += multi * power * (1 / (mau * 1.0));
    }
    
    cout << "S(" << x << ", " << n << ") = " << sum + 1;
    
    return 0;
}