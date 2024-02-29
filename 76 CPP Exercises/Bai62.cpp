#include <iostream>

using namespace std;

int UCLN (int a, int b)
{
    while ( a != b)
    {
        if (a > b)
            a = a - b;
            
        else
            b = b - a;
    }

    return a; 
}

int main ()
{
    int a, b;
    
    cout << "Nhap a: ";
    cin >> a;

    cout << "Nhap b: ";
    cin >> b;

	if (a == 0 || b == 0)
		cout << "Khong co uoc chung lon nhat doi voi 0 !";
		
	else
	{ 
	    int result = UCLN (a, b);
	    
	    cout << "Uoc chung lon nhat la: " << result;
	    cout << "\n";
	}
	
	return 0;
}
