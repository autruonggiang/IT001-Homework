#include<iostream>

using namespace std;

int main()
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
		cout << "Cac uoc so cua " << n << " la: ";
		
	for (int i = 1; i <= n; i++)
	{
	    if (n % i == 0)
	    {
	    	if (i % 2 == 1)
	    	cout << i << " ";
	    }
	    
    	i++;
	}
	
	return 0;
}
