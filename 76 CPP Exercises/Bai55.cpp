#include <iostream>
#include <math.h>

using namespace std;

int len (long long int n) {
    
    int length = 1;
    
    while ( n /= 10) {
        length++;
    }
    
    return length;
}


int main()
{
    long long int n, temp;
    int first;
    int dem = 1;

    cout << "Hay nhap so nguyen duong n: ";
    cin >> n;
    
    while (n < 0) {
        cout << "Hay nhap so nguyen duong n: ";
        cin >> n;
    } 
    
    temp = n;
    
    int du = pow(10, len(temp) - 1);
    first = (temp - temp % du) / pow(10, len(temp) - 1);
    
    while (temp -= temp - temp%du) {
		du = pow(10, len(temp) - 1);
		
	    if ((temp - temp % du) / pow(10, len(temp) - 1) == first)
	        dem++;
	}

    cout << "Chu so dau tien cua " << n << " la: " << first << endl;
    
    cout << "So luong chu so dau tien cua " << n << " la " << dem;
    
    return 0;
}


