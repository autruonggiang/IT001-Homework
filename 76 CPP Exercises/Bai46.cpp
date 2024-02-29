#include<iostream>
#include<math.h>

using namespace std;

int main ()
{
	long long int temp, n;
	int count = 0;
	
	do
	{
		cout << "Nhap n: ";
    	cin >> n;
    	
    	if (n <= 0)
    	{
    		cout << "Xin hay nhap lai !\n";
    	}
	}
	
	while (n <= 0);
	temp = n;
	
	if (n == 0) count = 1;
	
	while (temp != 0)
	{
    	if (temp % 2 == 1)
			count++;
		    temp /= 10;
	}
	
	cout << "So chu so le cua " << n << " la: " << count;
	
	return 0; 
}
 
