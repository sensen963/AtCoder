#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
//#include <function>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  int N ,K;
  cin >> N >> K;
  string sss;
  cin >> sss;
  int tmp, tmp1, tmp2;
  tmp = 0;
  vector<int> len_0, len_1;
  /*
  if (sss[0] == '1'){
    REP(i, N){
      if (sss[i] != '1') {
        tmp = i;
        break;
      }
    }
  }
  */
  tmp1 = 1;
  tmp2 = 0;
  for(int i = 0; i < N; i++){
    if (i != N - 1){
      if (sss[i] == '0'){
        if (tmp1 == 0) tmp2++;
        else {
          len_1.push_back(tmp2);
          tmp2 = 1;
          tmp1 = 0;
        }
      }else{
        if (tmp1 == 1) tmp2++;
        else {
          len_0.push_back(tmp2);
          tmp2 = 1;
          tmp1 = 1;
        }
      }
    }else{
      if (sss[i] == '0'){
        if (tmp1 == 0) {
          tmp2++;
          len_0.push_back(tmp2);
        }else {
          len_1.push_back(tmp2);
          tmp2 = 1;
          tmp1 = 0;
          len_0.push_back(1);
        }
      }else{
        if (tmp1 == 1) {
          tmp2++;
          len_1.push_back(tmp2);
        }
        else {
          len_0.push_back(tmp2);
          tmp2 = 1;
          tmp1 = 1;
          len_1.push_back(1);
        }
      }
    }
  }

  len_0.push_back(0);
  len_1.push_back(0);

  int tmp_max = len_1[0];
  REP(i, K){
    tmp_max += len_0[i];
    tmp_max += len_1[i+1];
    if (tmp_max == N) {
      cout << N << endl;
      return 0;
    }
  }
  int tmp_tmp = tmp_max;
  for(int i = 0; i < len_0.size() - K - 1; i++){
    tmp_tmp = tmp_tmp + len_0[i+K] + len_1[i+K+1] - len_0[i] - len_1[i];
    //cout << tmp_tmp << endl;
    tmp_max = max(tmp_tmp, tmp_max);
    if (tmp_max == N) {
      cout << N << endl;
      return 0;
    }
  }

  cout << tmp_max << endl;


  //for(auto aa: len_1) cout << aa << ":";
  //cout << endl;
  //for(auto aa: len_0) cout << aa << ":";
  return 0;
}
