#include<iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    int multi = n, k = 0;
    bool check = true;
    
    while (multi != 1) {
        
        if (multi % 3 == 0) {
            multi /= 3;
            k++;
        } 
        
		else {
            check = false;
            
            break;
        }
    }

    if (check) {
        cout << n << " co dang 3^k va la: 3^" << k;
    } 
	
	else {
        cout << n << " khong co dang 3^k";
    }
    
    return 0;
}