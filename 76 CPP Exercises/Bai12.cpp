#include<iostream>

using namespace std;

int main() {
    int x, n;
    
    cin >> x >> n;
    
    int multi = 1, sum = 0;
    
    for (int i = 1; i <=n ; ++i) {
        multi *= x;
        sum += multi;
    }
    
    cout << sum;
    
    return 0;
}