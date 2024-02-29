#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int n;
    
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    
    float sum = 0;
    int gt = 1;
    
    for (float i = 1; i <= n; ++i) {
        gt *= i;
        sum = pow(sum + gt, 1 / (i +1 ));
    }
    
    cout << "Tong cua phep tinh la:" << sum;
    
    return 0;
}