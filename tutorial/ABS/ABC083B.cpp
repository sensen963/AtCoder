#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int n, a, b;

  cin >> n >> a >> b;


  int res = 0;
  int num = 0;
  int auau;
  for (int i = 1; i <= n; i++){
    num = 0;
    auau = i;
    while(true){
      num += auau % 10;
      auau /= 10;
      if (auau == 0) break;
    }
    if (num >= a && num <= b) res += i;
  }

    cout << res << endl;

  return 0;
}
