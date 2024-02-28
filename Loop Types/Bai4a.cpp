#include <iostream>

using namespace std;

int main() {
  int n;
  long sum;
  
  sum = 0;
  cout << "Nhap n: " << endl;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  
  cout<<"Tong = "<<sum;
}
