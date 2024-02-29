#include <iostream>

using namespace std;

int main()
{
    int n, t, temp;
    int sum = 0;
    
    cout << "Hay nhap so nguyen duong n: ";
    cin >> n;
    
    if (n < 0) {
    	cout << "N khong hop le, moi nhap lai!";
    }
    
    for (temp = n; temp != 0; temp = temp / 10) {
        t = temp % 10;
        sum = sum * 10 + t;
    }
    
	if (n == sum)
        cout << " Day so " << n << " doi xung.";
        
    else
        cout << " Day so " << n << " khong doi xung.";

    return 0;
}
