#include<iostream>
#include<math.h>

using namespace std;

int main ()
{
    long long int temp, n;
    
	int P = 1;
	
	do
	{
		cout << "Nhap so n: ";
    	cin >> n;
    	
    	if (n <= 0)
    	{
    		cout << "Xin hay nhap lai !\n";
    	}
	} 
	
	while (n <= 0);
		temp = n;
		
	while (temp != 0)
	{
    	P = P * (temp % 10);
    	temp = temp / 10;
	}
	
	cout << "Tich cac chu so cua " << n << " la: " << P;
	
	return 0;
}
