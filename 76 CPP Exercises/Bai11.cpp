#include<iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int sum = 0, multi = 1;
    
    for (int i = 1; i <= n; ++i) {
        multi *= i;
        sum += multi;
    }
    
    cout << sum;

    return 0;
}