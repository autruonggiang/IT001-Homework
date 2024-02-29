#include<iostream>

using namespace std;

int main() {
    
    int k ;
    cin >> k;
    
    float sum;
    
    for (float i = 2; i <= k; ++i) {
        sum = (1 + i) * i / 2;
        if (sum > k) {
            sum = sum - i;
            
            break;
        } 
		
		else if (sum == k) {
            break;
        }
    }
    
    cout << sum;
    
    return 0;
}