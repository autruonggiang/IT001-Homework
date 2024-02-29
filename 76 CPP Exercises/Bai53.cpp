#include<iostream>

using namespace std;

int main()
{
	int i;
	long long int n, temp;
	int m = 1;
	int dem = 1;
  
	cout << "Hay nhap so nguyen duong n: ";
	cin >> n;
  
	while (n < 0) {
		cout << "Hay nhap so nguyen duong n: ";
		cin >> n;
	}
  
	temp = n;
  
	do
	{
	    i = n % 10;
	    
	    if (i == m) {
	        dem++;
    }
    
	    if (i > m) {
	      m = i;
	      dem = 1;
	    }
  	} 
	
	while (n /= 10);
	  
	cout << "Chu so lon nhat cua " << temp << " la: " << m << endl;

	cout << "So luong chu so lon nhat cua " << temp << " la " << dem;
	
	return 0;
}
