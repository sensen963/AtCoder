#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  long long n, y;

  cin >> n >> y;

  y /= 1000;

  long long res = 10 * n - y;

  int i,j;
  bool isend = false;
  int count = res / 9 + 1;
  //if (double(res) / 9.0 == 0) count = res / 9 + 1; else count = res / 9;
  for (i = 0; i < count; i++){
    if (((res - 9 * i) % 5 == 0) && (res - 9 * i >= 0)){
      j = (res - 9 * i) / 5;

      if (i + j <= n){
        isend = true;
        break;
      }
    }
  }

  if (isend){
    cout << n - i - j << " " << j << " " << i << endl;
  }else{
    cout << -1 << " " << -1 << " " << -1 << endl;
  }

  return 0;

}
