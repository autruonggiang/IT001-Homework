#include<iostream>

using namespace std;

int UCLN(int a, int b) {
    int temp = a;
    
    if (b > a) {a = b; b = temp; temp = a;}
    
    if (b != 0) {
        a = b;
        b = temp % a;
        UCLN(a, b);
    } 
	
	else {
        return a;
    }
}

int main() {
    int a, b;
    
    cout << "Nhap a, b (VD:5 10): ";
    cin >> a >> b;
    
    cout << "UCLN: " << UCLN(a, b);
    
    return 0;
}