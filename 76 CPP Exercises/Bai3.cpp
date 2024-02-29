#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Nhap n ";
    cin >> n;

    float sum = 0;
    
    for (float i = 1; i <= n; ++i) {
        sum += 1 / i;
    }

    cout << "Tong day so la " << sum;
    
    return 0;
}