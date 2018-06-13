
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int a, b;

  cin >> a >> b;

  int n, x;

  n = b - a - 1;

  x = n * (n + 1) / 2 - a;
  //cout << n << endl;

  cout << x << endl;


  return 0;

}
