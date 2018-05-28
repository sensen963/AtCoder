#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int a;
  cin >> a;

  int max_v = 0;

  for(int i = 2; i < 32; i++){
    int tmp = i;
    if (tmp * i > a){
      tmp = i;
    }else{
      while(tmp <= a){
        tmp *= i;
      }
    }
    max_v = max(max_v, tmp/i);
  }

  cout << max_v <<endl;

  return 0;
}
