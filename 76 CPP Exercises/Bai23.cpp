#include <iostream>

using namespace std;

int main ()
{
    int i, n;
    int count;
    
    cout << "\nNhap n: ";
    
    do
    {
    	cin >> n;
    	
    	if (n <= 0)
    	{
    		cout << "\nNhap lai n = ";
    	}
    }
    
	while (n <= 0);
	
    i = 1;
    count = 0;
    
    while (i <= n)
    {
    	if (n % i == 0)
        {
           count++;
        }
        
		i++;
    }
    
    cout << "\nSo luong cac uoc so cua " << n << " la: " << count;
    
    return 0;
}
