#include <iostream>

using namespace std;
 
int main()
{
    int so;
    
    cout << "Nhap so can dao nguoc: ";
    cin >> so;
    
    cout << "So dao nguoc cua " << so  << " la ";
    
    for (; so != 0; so = so / 10) {
        cout << so % 10;
    }
    
    return 0;
}
