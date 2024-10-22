#include <iostream>

using namespace std;

int main() {
   int n;
   cin >> n;
   int sum = 0;
   while (n--) {
      int A;
      cin >> A;
      int x = A % 10;
      A /= 10;
      int prod = 1;
      while (x--) prod *= A;
      sum += prod;
   }
   cout << sum;
   return 0;
}