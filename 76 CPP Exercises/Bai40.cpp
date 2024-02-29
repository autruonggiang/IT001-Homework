#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int x, n;
    
    cout << "Nhap x, n (VD: 5 10): ";
    cin >> x >> n;
    
    float sum = 0;
    unsigned long long int multi = 1;
    
    for (float i = 1; i <=n; ++i) {
        multi *= x;
        sum = pow(sum + multi, 0.5);
    }
    
    cout << "S(" << n << "): " << sum;
    
    return 0;
}