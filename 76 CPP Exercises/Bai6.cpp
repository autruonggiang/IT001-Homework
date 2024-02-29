#include <iostream>

using namespace std;

int main() {
	int n;
	
    cout << "S(n): ";
    cin >> n;
    
    float sum = 0, mau;
    
    for (float i = 1; i <= n; ++i) {
        mau = i * (i + 1);
        sum += 1 / mau;
    }

    cout << "S(" << n << "): " << sum;
	
	return 0;
}
