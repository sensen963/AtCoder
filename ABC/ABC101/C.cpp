#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int N, K;
  cin >> N >> K;

  int a[100001];
  int auau, iter;
  for (int i = 0; i < N; i++){
    auau = scanf("%d",&a[i]);
    if (a[i] == 1) iter = i;
  }

  int num;

  // if (iter < K || ((N - iter) < K)) {
  //   num = int(ceil(double(N - 1) / double(K - 1)));
  // }else{
  //   num = int(ceil(double(iter) / double(K - 1)) + ceil(double(N - iter - 1) / double(K - 1)));
  // }

  num = min(int(ceil(double(N - 1) / double(K - 1))), int(ceil(double(iter) / double(K - 1)) + ceil(double(N - iter - 1) / double(K - 1))));


  cout << num << endl;



  return 0;

}
