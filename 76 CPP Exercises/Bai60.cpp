#include <iostream>

using namespace std;

int main()
{
	int n;
	
	cout << "Hay nhap so nguyen duong n: ";
	cin >> n;
	
	while (n < 0) {
		cout << "N khong hop le, moi nhap lai: ";
		cin >> n;
	}
    
	bool Test = true;
	int temp = n;
	int Last = temp % 10;
	temp /= 10;
	
	while (temp != 0)
	{
		int preLast = temp % 10;
		temp /= 10;
		
		if (Last < preLast)
		{
			Test = false;
			break;
		}
	
	    else
	    {
	      Last = preLast;
	    }
	}
	
	if (Test)
    	cout << "Day la day so tang dan";
    	
	else
		cout << "Day khong phai la day so tang dan";
		
	return 0;

}
