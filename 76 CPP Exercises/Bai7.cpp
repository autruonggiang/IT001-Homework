#include <iostream>

using namespace std;

int main() {
	int n;
	
    cout << "S(n): ";
    cin >> n;
    
    float sum = 0, mau, tu;
    
    for (float i = 1; i <= n; ++i) {
        tu = i;
        mau = i + 1;
        
        sum += tu / mau;
    }

    cout << "S(" << n << "): " << sum;
	
	return 0;
}
