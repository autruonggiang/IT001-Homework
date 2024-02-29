#include <iostream>

using namespace std;

bool KiemTraSNT (int n)
{	
	if (n <= 1) 
		return false;
	
	if (n <= 2)
		return true;
	
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) 
		{
			return false;
		}
	}
	
	return true;
}

int main ()
{
	int n;
	
	cout << "Nhap n: ";
	cin >> n;
	
	if (KiemTraSNT (n))
		cout << "La so nguyen to !";
		
	else 
		cout << "Khong la so nguyen to !";
		
	return 0;
}
