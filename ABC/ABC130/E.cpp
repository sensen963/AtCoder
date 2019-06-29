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

  const ll MOD = 1e9 + 7;
  ll N, M;
  cin >> N >> M;
  vector<ll> v1(N), v2(M);
  REP(i, N) cin >> v1[i];
  REP(i, M) cin >> v2[i];

  //ll dp[N][M] = {{0}};
  vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0LL));
  vector<vector<ll>> sum(N + 1, vector<ll>(M + 1, 0LL));
  //ll sum[N][M] = {{0}};

  REP(i, N){
    REP(j, M){
      if (v1[i] == v2[j]){
        dp[i + 1][j + 1] = (sum[i][j] + 1) % MOD;
      }
      sum[i + 1][j + 1] = (((((sum[i + 1][j] - sum[i][j]) % MOD)  + sum[i][j + 1]) % MOD) + dp[i + 1][j + 1]) % MOD;
    }
  }
  //ll ans = (sum[N][M] + 1) % MOD;
  ll ans = 1;
  REP(i, N)REP(j, M) ans = (ans + dp[i + 1][j + 1]) % MOD;
  cout << ans << endl;

  return 0;
}
