#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int n, r;
  cin >> n;

  long long a[n];
  for(int i=0; i < n; i++){
    r = scanf("%lld", &a[i]);
  }
  int ming = 999999;
  int res = 0;
  for (int i = 0; i < n; i++){
    while(true){
      if ((a[i] % 2 == 0) && (a[i] != 0) && (res < ming)){
        a[i] /= 2;
        res++;
      }else{
        break;
      }
    }
    ming = min(ming, res);
    if (ming == 0) break;
    res = 0;

  }

  cout << ming << endl;

  return 0;

}
