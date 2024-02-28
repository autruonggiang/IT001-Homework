#include <iostream>

using namespace std;

int main()
{
  int n, gt, sum;
  gt = 1;
  sum = 0;
  
  cout << "Nhap n:" << endl;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    gt = gt * i;
    sum = sum + gt;
  }
  
  cout << "Tong = " << sum;
}
