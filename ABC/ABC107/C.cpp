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
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPL(i, n) for(ll i = 0; i < (ll)(n); i++)
#define LookV(array) for(auto iter = array.begin(); iter != array.end(); iter++) {cout << iter* << ", ";} cout << endl;

int main() {

  ll N, K;

  cin >> N >> K;

  vector<ll> x(N);
  REPL(i, N){
    cin >> x[i];
  }

  ll init_zero = N;
  REPL(i, N){
    if (x[i] > 0){
      init_zero = i;
      break;
    }
  }
  //cout << init_zero << endl;

  ll sum_x = 0;
  if (init_zero == 0) {
    sum_x = x[K-1];
  }else if (init_zero == N) {
    sum_x = -1 * x[N-K];
  }else{
    vector<ll> pos, neg;
    for (ll i = init_zero; i < N; i++){
      pos.push_back(x[i]);
    }
    for (ll i = init_zero - 1; i >= 0; i--){
      neg.push_back(-1 * x[i]);
    }
    // ll tmp = 0;
    // for (ll i = 0; i != neg.size(); i++){
    //   tmp = 2 * neg[i] + pos[]
    // }

    ll tmp = INF;

    if (init_zero + K - 1 <= N - 1) tmp = min(tmp, x[init_zero - 1 + K]);
    if (init_zero - K >= 0) tmp = min(tmp, -1 * x[init_zero - K]);

    for (ll i = 0; i < neg.size(); i++){
      if ((pos.size() >= K - i - 1) && (K - i - 1 > 0)){
        tmp = min(tmp, neg[i]*2 + pos[K - 2 - i]);
        tmp = min(tmp, neg[i] + pos[K - 2 - i] * 2);
      }

    }

    sum_x = tmp;


    //for (int i = 0; i != pos.size(); i++) cout << pos[i] << endl;
    ///for (int i = 0; i != neg.size(); i++) cout << neg[i] << endl;
  }

  cout << sum_x << endl;


  return 0;
}
