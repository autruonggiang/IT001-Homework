#include<iostream>

using namespace std;

int main ()
{
	int n, max = 1;
	
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
	
	cout << "Cac uoc so le cua " << n << " la: ";
	
	for (int i = 1; i <= n; i++)
	{
		if ((n % i == 0) && (i % 2 == 1))
	    	{
		    	if (i > max)
		    	{
					max = i;
		    	}
		    	
	    		cout << i << " ";
    		}
  }
  
	cout << "\nUoc so le lon nhat cua " << n << " la: " << max;
	
	return 0;
}
