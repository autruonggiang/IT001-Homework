#include <iostream>

using namespace std;

int main() {
    int n;
    
    cout << "Nhap n ";
    cin >> n;

    int sum = 0;
    
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    cout << "Tong day so la " << sum;
    
    return 0;
}