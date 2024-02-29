#include<iostream>
#include<math.h>

using namespace std;

int main() {
    
    int x, n;
    
    cout << "S(x, n): ";
    cin >> x >> n;
    
    unsigned long long int multi = 1;
    long long int sum = 0;
    float power;
    
    for (float i = 1; i <= n; ++i) {
        multi *= x;
        power = pow(-1, i + 1);
        
        sum += power * multi;
    }
    
    cout << "S(" << x << ", " << n << ") = " << sum;
    
    return 0;
}