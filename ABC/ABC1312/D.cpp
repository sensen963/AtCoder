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

ll powmod(ll a, ll p, ll MOD) {
	ll ans = 1;
	ll mul = a;
	for (; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
		if ((p & 1) == 1)ans = (ans * mul) % MOD;
	}
	return ans;
}

ll combmod(ll n, ll r, ll MOD){
  if(n < r) return 0LL;
  if (n < 0 || r < 0) return 0LL;
  vector<ll> ff(n+1), vff(n+1);
  // 1! ~ n!
  ff[0] = 1;
  for(ll i = 1; i < n + 1; i++) {
    ff[i] = ff[i - 1] * i % MOD;
  }
  // n!^(MOD-2) (= n!^(-1))
  ll inv = powmod(ff[n], MOD - 2, MOD);

  // n!^(-1) ~ 1!^(-1)
  vff[n] = inv;
  for(ll i = n - 1; i >= 0; i--) {
    vff[i] = vff[i + 1] * (i + 1) % MOD;
  }

  // n combination r
  ll comb = (((ff[n] * vff[r]) % MOD) * vff[n - r]) % MOD;

  return comb;
}


int main() {
  int N, K;
  cin >> N >> K;
  const ll MOD = 1e9 + 7;

  ll left, right, ans;

  for(int i = 1; i <= K; i++){
    if (i == 1){
      left = N - K + 1;
      right = 1;
    }else{

      right = combmod(N - K +1, i, MOD);
      left = combmod(K - 1, i - 1, MOD);

    }

    left %= MOD;
    right %= MOD;
    ans = left * right;
    ans %= MOD;
    cout << ans << endl;
  }
}
