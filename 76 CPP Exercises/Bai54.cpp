#include<iostream>

using namespace std;

int main()
{
	int i;
	long long int n, temp;
	int m;
	int dem = 0;
  
	cout << "Hay nhap so nguyen duong n: ";
	cin >> n;
    
	while (n < 0) {
		cout << "Hay nhap so nguyen duong n: ";
		cin >> n;
	}

	if (n == 0) {
		m = 0;
	}
  
	temp = n;
	m = n % 10;
  
	do
	{
		i = n % 10;
		
		if (i == m) {
		    dem++;
		}
	
		if (i < m) {
		  m = i;
		  dem = 1;
		}
	}
	
	while (n /= 10);
	
	cout << "Chu so nho nhat cua " << temp << " la: " << m << endl;
	
	cout << "So luong chu so nho nhat cua " << temp << " la " << dem;
	
	return 0;
}
