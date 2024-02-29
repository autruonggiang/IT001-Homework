#include<iostream>

using namespace std;

int main() {
    int n;
    
    cout << "T(n): ";
    cin >> n;
    
    int multi = 1;
    
    for (int i = 1; i <= n; ++i) {
        multi *= i;
    }
    
    cout << "T(" << n << "): " << multi;
    
    return 0;
}