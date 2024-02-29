#include<iostream>

using namespace std;

int main() {
    int x, n;
    
    cin >> x >> n;
    
    int multi = x, sum = 0;
    
    for (int i = 0; i <=n ; ++i) {
        sum += multi;
        multi *= x * x;
    }
    
    cout << sum;
    
    return 0;
}