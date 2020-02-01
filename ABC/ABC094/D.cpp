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

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)

ll MOD = pow(10, 9) + 7;

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

    ll n;
    cin >> n;
    vector<ll> A(n);
    REP(i, n) cin >> A[i];

    sort(A.begin(), A.end());

    ll cn = A[n-1];

    int l = 0;
    int r = n-2;
    while(r - l > 1){
        int tmp = (r + l) / 2;
        double val = (double)A[tmp] - (double)cn / 2.0;
        if (val < 0) l = tmp;
        else r = tmp;

    }

    double a = abs((double)cn / 2.0 - A[r]);
    double b = abs((double)cn / 2.0 - A[l]);

    ll cr = a < b ? A[r] : A[l];
    cout << cn << " " << cr << endl;

    return 0;
}
