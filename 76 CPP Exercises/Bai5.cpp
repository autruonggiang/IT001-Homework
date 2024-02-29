#include <iostream>

using namespace std;

int main() {
	int n;
    cout << "S(n): ";
    cin >> n;
    
    float sum = 0;
    
    for (float i = 0; i <= n; ++i) {
        sum += 1 / (2 * i + 1);
    }

    cout << "S(" << n << "): " << sum;
    
	return 0;
}
