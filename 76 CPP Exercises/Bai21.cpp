#include <iostream>

using namespace std;
 
int main () 
{
    int n;
    	cout << "Nhap n: ";
    	
    do {
        cin >> n;
        
        if (n <= 0) {
            cout << "\nNhap lai n = ";
        }
    } 
	
	while( n <= 0);
	
    int sum = 0;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) { 
            sum += i;
        }
    }
    
    cout << "\nTong cac uoc so = " << sum << '\n';
    
    return 0;
}
