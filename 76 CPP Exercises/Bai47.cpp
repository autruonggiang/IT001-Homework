#include <iostream>

using namespace std;

int TongSoChan (long long int  N)
{
    int S = 0;
    
    while (N > 0)
    {
        int t = N % 10;

        if (t % 2 == 0)
            S += t;

        N = N / 10;
    }
    
    return S;
}

int main ()
{
    long long int N;
    
    cout << "Nhap N: ";
    cin >> N;

    int result = TongSoChan (N);
    
    cout << "Tong cac chu so chan la : " << result << endl;
    
    return 0;
}
