#include<iostream>

using namespace std;

int main() {
    int x, n;
    
    cout << "T(x, n): ";
    cin >> x >> n;
    
    int multi = 1;
    
    for (int i = 1; i <= n; ++i) {
        multi *= x;
    }
    
    cout << "T(" << x << ", " << n << "): " << multi;
    
    return 0;
}