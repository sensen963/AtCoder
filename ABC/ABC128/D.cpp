
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


int main() {

  int N, K;
  cin >> N >> K;
  vector<ll> V(N);
  REP(i, N) cin >> V[i];

  std::vector<ll> acc_l(N), acc_r(N);
  REP(i, N){
    if (i == 0) {
      acc_l[0] = V[0];
      acc_r[N - 1] = V[N - 1];
    }else{
      acc_l[i] = acc_l[i - 1] + V[i];
      acc_r[N - 1 - i] = acc_r[N - i] + V[N - 1 - i];
    }
  }
  //cout << "a" << endl;

  ll tmp = 0;
  ll tmp_l = 0;
  ll tmp_max = 0;
  vector<ll> p;
  REP(i, K + 1){
    if (i > N) continue;
    if (i == 0) tmp_l = 0;
    else{
      tmp_l = acc_l[i - 1];
    }
    REP(j, K + 1 - i){
      if (i + j > N) continue;
      if (j == 0) tmp = tmp_l;
      else if (j != 0){
        tmp = tmp_l + acc_r[N - j];
      }

      p = {};
      p.insert(p.end(), V.begin(), V.begin() + i);
      p.insert(p.end(), V.end() - j, V.end());
      //for(auto x : p) cout << x;
      //cout << endl;
      sort(p.begin(), p.end());
        //cout << "a" << endl;
      REP(k, K + 1 - i - j){
        //cout << i << " " << j << " " << k << " " << tmp << endl;
        if (k == 0) continue;
        if (k > p.size()) break;
        if (p[k - 1] > 0) break;

        tmp -= p[k - 1];
      }
      tmp_max = max(tmp_max, tmp);

      //cout << "a" << endl;

    }
  }

  cout << tmp_max << endl;


  return 0;
}
