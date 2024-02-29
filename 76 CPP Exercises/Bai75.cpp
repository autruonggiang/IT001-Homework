#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int multi = n, k = 0;
    bool check = true;
    
    while (multi != 1) {
        
        if (multi % 2 == 0) {
            multi /= 2;
            k++;
        } 
		
		else {
            check = false;
            
            break;
        }
    }

    if (check) {
        cout << n << " co dang 2^k va la: 2^" << k;
    } 
	
	else {
        cout << n << " khong co dang 2^k";
    }
    
    return 0;
}