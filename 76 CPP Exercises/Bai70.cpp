#include<iostream>
#include<math.h>

using namespace std;

int main() {
    
    int n;
    
    cout << "S(n): ";
    cin >> n;
    
    float sum = 0;
    unsigned long long int mau = 0;
    float power;
    
    for (float i = 1; i <= n; ++i) {
        mau += i;
        power = pow(-1, i+1);
        
        sum += power * (1 / (mau * 1.0));
    }
    
    cout << "S(" << n << ") = " << sum;
    
    return 0;
}