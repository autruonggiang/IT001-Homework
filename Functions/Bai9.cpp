#include<iostream>

using namespace std;

int fib(int n) {
    
    int sum = 0, head = 1, tail = 1;
    
    if (n == 1 || n == 2) {
        return 1;
    } 
	
	else {
        for (int i = 3; i <= n; ++i) {
            sum = head + tail;
            head = tail;
            tail = sum;
        }
    }
    
    return sum;
}

int main() {
    int n;
    
    cout << "Nhap n: ";
    cin >> n;
    
    cout << "Fib(" << n << ") = " << fib(n);

    return 0;
}