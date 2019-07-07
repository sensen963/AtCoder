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

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)


int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> s(M), e(M);
  map<ll, set<ll>> G, G1;
  REP(i, M) {
    cin >> s[i] >> e[i];
    G[s[i]].insert(e[i]);
    G1[s[i] * 3].insert(e[i] * 3 + 1);
    G1[s[i] * 3 + 1].insert(e[i] * 3 + 2);
    G1[s[i] * 3 + 2].insert(e[i] * 3);
  }
  ll S, T;
  cin >> S >> T;

  std::vector<ll> val(3 * N + 4, 4 * N);
  queue<ll> que;
  que.push(S * 3);
  ll tmp = S * 3;
  val[tmp] = 0;
  while(!que.empty()){
    tmp = que.front();
    que.pop();
    for(auto x : G1[tmp]){
      if (val[tmp] + 1 < val[x]){
        que.push(x);
        val[x] = val[tmp] + 1;
      }
    }

  }

  if (val[T * 3] == 4 * N) val[T * 3] = -3;
  cout << (val[T * 3] / 3) << endl;

  return 0;
}
