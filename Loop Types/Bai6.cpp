#include <stdio.h>
#include<math.h>
#include <iostream>
using namespace std;

bool ktsnt(int n)
{
    int i;
    if (n < 2) 
		return 0;
	
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
            
    return 1;
}

int tinh(int n)
{
    int i, s = 0;
    for (i = 2; i < n; i++)
        if (ktsnt(i) == 1)
            s = s + i;
            
    cout << "Tong gia tri cac so nguyen to nho hon n la " ;
    return s;
}

int main()
{
    int n;
    
    cout << "Nhap n ";
    cin >> n;
    
    cout << tinh(n);
    return 0;
}
