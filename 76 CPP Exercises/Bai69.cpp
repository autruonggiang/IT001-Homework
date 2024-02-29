#include<iostream>
#include<math.h>

using namespace std;

int main() {
    
    int x, n;
    
    cout << "S(x, n): ";
    cin >> x >> n;
    
    unsigned long long int multi = x;
    long long int sum = 0;
    float power;
    
    for (float i = 0; i <= n; ++i) {
        if (i != 0)
            multi *= x * x;
            power = (int) pow(-1, i);
            
	        sum += power * multi;
    }
    
    cout << "S(" << x << ", " << n << ") = " << sum;
    
    return 0;
}