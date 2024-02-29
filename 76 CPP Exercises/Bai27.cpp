#include <iostream>

using namespace std;

int Dem_UocSoChan (int N)
{
    int dem = 0;
    
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0 && i % 2 == 0)
        {
            dem++;
        }
    }

    return dem;
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
	
    int result = Dem_UocSoChan (N);
    
    cout << "So luong cac uoc so chan la: " << result << endl;

    return 0;
}
