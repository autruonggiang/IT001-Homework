#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int x, n;
    
    cout << "S(x, n): ";
    cin >> x >> n;
    
    float sum = 0;
    unsigned long long int mau = 1;
    unsigned long long int multi = 1;
    float power;
    
    for (float i = 1; i <= n; ++i) {
        multi *= x;
        mau *= i;
        power = pow(-1, i);
        
        sum += multi * power * (1 / (mau * 1.0));
    }
    
    cout << "S(" << x << ", " << n << ") = " << sum;
    
    return 0;
}