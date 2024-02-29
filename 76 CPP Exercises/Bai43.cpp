#include <iostream>

using namespace std;

int log (unsigned long long int  n) 
{
    unsigned long long int  dem = 0;
    
    while (n >= 10) 
	{
        n /= 10; 
        dem++;
    }
    
    return dem;
}

int main ()
{
    unsigned long long int  n;
    
    cout << "Nhap vao so nguyen n: ";
    cin >> n;
    
    cout << "So luong chu so cua so nguyen la: "<< log (n) + 1 << endl;
    
    return 0;
}
