#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){

  int a, b, c, k;

  cin >> a >> b >> c >>k;

  int d = max({a, b, c});

  int sum = a + b + c + int(pow(2, k)) * d - d;

  cout << sum << endl;

  return 0;
}
