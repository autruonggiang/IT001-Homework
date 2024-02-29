#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n,i;
    float sum;
    
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    
    sum = 0;
    
    for(int i = 1; i <= n; i++) {
        sum = sqrt(2 + sum);
    } 
    
    cout << "Tong cua phep tinh la: " << sum;
    
    return 

}
