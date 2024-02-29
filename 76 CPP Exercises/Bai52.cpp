#include<iostream>

using namespace std;

int main()
{
	int i, n, temp;
	
	cout << "Hay nhap so nguyen duong n: ";
	cin >> n;
    	
	if (n < 10)
	{
    	cout << "N khong hop le, moi nhap lai !";
    	return 0;
	}
	
	int m = n % 10;
	
    if (n == 0)
	{
   		m = 0;
	}
	
	temp = n;
	
	do
	{
    	i = n % 10;
    	
    	if (i < m)
    	{
    		m = i;
    	}
	}
	
	while (n = n / 10);
	
	cout << "Chu so nho nhat cua " << temp << " la: " << m;
	
	return 0;
}
