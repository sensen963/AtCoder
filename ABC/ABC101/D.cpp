#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int S(long long i){
  int tmp = 0;
  while(true){
    tmp += i % 10;
    i /= 10;
    if (i == 0) break;
  }
  return tmp;
}

long long next(long long tmp){

  int min_d = log(tmp);
  double amp;
  double min_tmp = tmp;
  long long aa;
  long long min_aa = tmp;
  for(int i = 0; i <= min_d; i++){
    aa = (tmp / long(pow(10, i)) + 1) * long(pow(10, i)) - 1;
    //cout << aa << endl;
    amp = double(aa) / double(S(aa));
    //cout << amp << endl;
    if (amp < min_tmp){
      min_tmp = amp;
      min_aa = aa;
      //cout << min_aa << endl;
    }
  }

  return min_aa;
}

int main(){
  int K;
  cin >> K;

  // for (long long i = 9; i < 10000; i += 10){
  //   int tmp = S(i);
  //   cout << i << " " << tmp << " " << double(i) / double(tmp) << endl;
  // }
  //cout << next(6) << endl;
  long long tmp = 1;
  for (int i = 0; i < K; i++){
    tmp = next(tmp);
    cout << tmp << endl;
    tmp++;
  }

  return 0;
}
