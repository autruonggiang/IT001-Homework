#include <iostream>

using namespace std;

int main(){
    int n, an, an1, an2, i;
    
    cout << "Nhap n: ";
    cin >> n;
    
    an2 = 1; an1 = 0;
    
    cout << "Phan tu dau tien cua day: " << n << "\n"; 
    
    for (i = 1; i <= n; i++) {
        an = an2 + an1;
        cout << an << " ";
        an2 = an1;
        an1 = an;
    }
    
    return 0;
}
