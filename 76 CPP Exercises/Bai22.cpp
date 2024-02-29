#include<iostream>

using namespace std;

int main ()
{
	int n;
	long P = 1;
	
	do
	{
		cout << "\nNhap n: ";
	    cin >> n;
	    
	    if (n <= 0)
	    {
	    	cout << "\nXin hay nhap lai !";
	    }
	} 
	
	while (n <= 0);
	
	cout << "Cac uoc cua " << n << " la: ";
	
	for (int i = 1; i <= n; i++)
	{
	    if (n % i == 0)
	    {
	    	cout << i << "\t";
	    	
	    	P = P * i;
	    }
	}
	
	cout << "\nTich cac uoc so cua " << n << " la: " << P;

	return 0;
}
