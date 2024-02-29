#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	
	while (n < 0 ) {
		cout << "Khong hop le, nhap lai n: ";
		cin >> n;
	} 
	
	bool check = true;
	
	while (n /= 10)
	{
		if ((n % 10) % 2 == 0)
		{
			check = false;
			break;
		}
	}
	
	(check) ? cout << "So nguyen n toan la so le" : cout << "So nguyen n khong toan la so le";
	
	return 0;
}

