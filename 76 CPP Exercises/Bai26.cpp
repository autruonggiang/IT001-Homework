#include <iostream>

using namespace std;
 
int fun (int n)
{
    int value = 1;
    
    for (int i = 1; i <= n; i++)
	{
        if (n%i == 0 && i%2==1)
		{
            value *= i;
        }
    }
    
    return value;
}
int main ()
{
    int number;
    
	do
	{
		cout << "\nNhap so: ";
		cin >> number;
		
	    if (number <= 0)
	    {
	      cout << "\nXin hay nhap lai !";
	    }
	}
	
	while (number <= 0);
	
    cout << "Tich tat ca uoc so le la: " << fun (number);
    
    return 0;
}
 
