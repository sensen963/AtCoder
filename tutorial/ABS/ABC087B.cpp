#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
  int a, b, c, x;

  cin >> a >> b >> c >> x;

  x /= 50;

  int res = 0;

  for (int i = 0; (10 * i) <= x; i++){
    for (int j = 0; (10 * i + 2 * j) <= x; j++){
      int k = x - (10 * i + 2 * j);
      if((i <= a) && (j <= b) && (k <= c)) res++;
    }
  }

  cout << res << endl;

  return 0;
}
