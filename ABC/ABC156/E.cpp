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
vector<ll> ff(1e6), vff(1e6);

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
  // n combination r
  ll comb = (((ff[n] * vff[r]) % MOD) * vff[n - r]) % MOD;

  return comb;
}


void init(ll n){
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
}

int main() {
    ll N, K;
    cin >> N >> K;
    init(2*N+10);
    if (K >= N-1){
        cout << combmod(2*N-1, N, MOD) << endl;
        return 0;
    }
    ll hoge = (N * (N - 1) + 1) % MOD;
    for(ll i = 2; i <= K; i++){
        ll tmp = (combmod(N - 1, i, MOD) * combmod(N, i, MOD)) % MOD;
        hoge= (hoge + tmp) % MOD;
    }


    cout << hoge << endl;
    return 0;
}
