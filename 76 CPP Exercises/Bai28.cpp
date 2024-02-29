#include <iostream>

using namespace std;

int Tong_UocSo (int N)
{
    int S = 0;
    
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            S = S + i;
        }
    }

    return S;
}

int main ()
{
    int N;
	do
	{
		cout << "\nNhap N: ";
		cin >> N;
		
	    if (N <= 0)
	    {
	      cout << "\nXin hay nhap lai !";
	    }
	} 
	
	while (N <= 0);
	
    int result = Tong_UocSo (N);
    
    cout << "Tong cac uoc nho hon n la: " << result - N;
    cout << endl;
    
    return 0;
}
