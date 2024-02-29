#include <iostream>

using namespace std;

int main(){
	int n;
	
    cout << "S(n): ";
    cin >> n;
    
    float sum = 0, mau, tu;
    
    for (float i = 0; i <= n; ++i) {
        tu = 2 * i + 1;
        mau = 2 * i + 2;
        sum += tu / mau;
    }

    cout << "S(" << n << "): " << sum;
    
	return 0;
}
