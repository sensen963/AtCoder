#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){


  int n;
  long long tmp, cmp;
  int amp = 0;

  cin >> n;

  for (int i = 0; i < n; i++){
    cmp = scanf("%lld", &tmp);

    while(true){
      if (tmp % 2 != 0){
        break;
      }else{
        tmp /= 2;
        amp++;
      }
    }
  }
  cout << amp <<endl;

  return 0;
}
