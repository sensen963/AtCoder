#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
  long long N;

  cin >> N;

  long long N1 = N;

  long long tmp = 0;

  while(true){
    tmp += (N % 10);
    //cout << tmp << endl;
    N /= 10;
    if (N == 0) break;
  }
  if ((N1 % tmp) == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}
