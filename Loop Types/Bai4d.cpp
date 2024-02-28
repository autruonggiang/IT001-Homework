#include <iostream>

using namespace std;

int main()
{
  int n, gt;
  gt = 1;
  
  cout << "Nhap n: " << endl;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    gt = gt * i;
  }
  
  cout << "Tong = " << gt;
}
