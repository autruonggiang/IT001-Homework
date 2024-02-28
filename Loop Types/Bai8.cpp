#include <iostream>

using namespace std;

int main()
{
	int nN = 0;
	int a = 0;
	int b = 0;
	
	cout << "Tat ca cac so thoa dieu kien a * b = 2 * (a+b) trong pham vi tu 10 den 99 la: ";
	
	for (int i = 10; i <= 99; i++)
	{
		a = i / 10;
		b = i % 10;
		
		if ((a * b) == 2 * (a + b))
		{
			cout << i << " "; 
		}
	}
	
	return 0;
}

 
