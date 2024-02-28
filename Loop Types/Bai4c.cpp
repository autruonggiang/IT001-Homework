#include <iostream>

using namespace std;

int main()
{
	int n;
	float sum;
	sum = 0;
	
	cout < <"Nhap n:" << endl;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		sum = sum + 1.0 / i;
	}
	
	cout<<"Tong = "<<sum;
}
