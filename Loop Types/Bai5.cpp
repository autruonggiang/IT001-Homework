#include <iostream>

using namespace std;

int main()
{
    int a, b, n;
    cout << "Nhap n = ";
    cin >> n;
    
    do
    {
        cout << "Nhap a = ";
        cin >> a;
    } 
	
	while ( a >= n );
	
    do
    {
        cout << "Nhap b = ";
        cin >> b;
    } 
	
	while ( b >= n );
    
    int s = 0;
    
    for (int i = 1; i < n; i++)
    {
        if ((i % a == 0) && (i % b != 0))
            s += i;
    }
    
    cout << "Tong cac so nguyen duong nho hon " << "" << n << " chia het cho " << "" << a << " khong chia het cho "<< "" << b << ":" << s;
    
	return 0;
}


