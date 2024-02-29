#include <iostream>

using namespace std;

int main() {
	int n;
	
    cout << "S(n): ";
    cin >> n;
    
    float sum = 0;
    
    for (float i = 1; i <= n; ++i) {
        sum += 1 / (2 * i);
    }

    cout << "S(" << n << "): " << sum;
    
	return 0;
}
