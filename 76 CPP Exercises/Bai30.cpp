#include <iostream>

using namespace std;

bool Check_SHT (int N)
{
    int S = 0;
    
    for (int i = 1; i < N; i++)
        if (N % i == 0)
            S += i;

    if (S == N)
        return true; 
        
    return false;     
}

int main()
{
    int N;
    
    cout << "Nhap n: ";
    cin >> N;

    bool result = Check_SHT (N);
    
    if (result == true)
        cout << "La so hoan thien !";
        
    else
        cout << "Khong la so hoan thien !";

    cout << endl;
    
    return 0;
}
