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
#include<unordered_map>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPI(i, init, n) for(ll i = init; i < (ll)(n); i++)

class DP{
public:

  vector<unordered_map<ll, ll>> dp;
  vector<ll> divable;
  map<ll, ll> a;

  DP(ll N, ll K){
    //cout << "init" << endl;

    //vector<vector<ll>> dp1(K + 1, vector<ll>(N + 1));
    vector<unordered_map<ll, ll>> dp1(K + 1);
    //cout << "init" << endl;
    dp = dp1;

    std::vector<ll> v;
    divable = v;
    for (ll i = 1; i * i <= N; i++){
      divable.push_back(i);
      divable.push_back(N/i);
    }
    sort(divable.begin(), divable.end());
    divable.erase(unique(divable.begin(), divable.end()), divable.end());

    map<ll, ll> a1;
    a = a1;
    REP(i, divable.size() - 1){
      a[divable[i + 1]] = divable[i + 1] - divable[i];
    }

    REPI(i, 1, K + 1){
      for(ll j = divable.size() - 1; j >= 0; j--){
        ll dj = divable[j];
        if (i == 1) dp[1][dj] = 1;
        else if (dj == N) dp[i][dj] = dp[i - 1][1];
        else{
          ll tmp = N / dj;
          ll tmp1 = (dp[i - 1][tmp] * a[tmp]) % MOD;
          dp[i][dj] = (dp[i][divable[j + 1]] + tmp1) % MOD;
        }
      }
      //cout << i << endl;
    }

  }



};

int main() {
  ll N, K;
  cin >> N >> K;

  auto table = DP(N, K + 1);
  // REP(i, K + 2) {
  //   REP(j, N + 1) cout << table.dp[i][j] << " ";
  //   cout << endl;
  // }
  cout << table.dp[K+1][1] << endl;

  return 0;
}
