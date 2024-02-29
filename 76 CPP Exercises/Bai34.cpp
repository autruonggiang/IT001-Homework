#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, i;
    float sum;
    
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    
    if (n > 0) {
        sum = 0;
        
        for(int i = 1; i <= n; i++) {
            sum = sqrt(i + sum);
        }
        
    	cout << "Tong cua phep tinh la:" << sum;
    } 
    
    else {
        cout << "N khong hop le, moi nhap lai.";
    }
    
    return 0;
}
