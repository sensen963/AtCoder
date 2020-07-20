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
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

ll MOD = pow(10, 9) + 7;

ll powmod(ll a, ll p, ll MOD) {
	ll ans = 1;
	ll mul = a;
	for (; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
		if ((p & 1) == 1)ans = (ans * mul) % MOD;
	}
	return ans;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
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

    ll N, a, b;

    cin >> N >> a >> b;

    ll tmp = powmod(2, N, MOD) - 1;

    ll tmp1 = 1, tmp2 = 1;
    for (ll i = N; i > N - a; i--) tmp1 = (tmp1 * i % MOD);
    for (ll i = a; i > 0; i--) tmp2 = (tmp2 * i % MOD);
    tmp1 = (tmp1 * modinv(tmp2, MOD)) % MOD;
    tmp = (tmp - tmp1 + MOD) % MOD;


    tmp1 = 1, tmp2 = 1;
    for (ll i = N; i > N - b; i--) tmp1 = (tmp1 * i % MOD);
    for (ll i = b; i > 0; i--) tmp2 = (tmp2 * i % MOD);
    tmp1 = (tmp1 * modinv(tmp2, MOD)) % MOD;
    tmp = (tmp - tmp1 + MOD) % MOD;

    cout << tmp << endl;
    return 0;
}
