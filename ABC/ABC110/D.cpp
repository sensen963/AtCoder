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
const ll MOD = pow(10, 9) + 7;

ll powmod(ll a, ll p, ll MOD) {
	ll ans = 1;
	ll mul = a;
	for (; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
		if ((p & 1) == 1)ans = (ans * mul) % MOD;
	}
	return ans;
}

ll combmod(ll n, ll r, ll MOD){
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

  ll n, m;
  cin >> n >> m;

  ll tmp = m;


  ll count = 0;
  ll iter = 2;

  ll ans0, ans1, ans2;
  ll ans = 1;

  //ans1 = fact(n-1);
  while(tmp != 1){
    if (tmp % iter != 0) {
      iter++;
      if (count != 0){
        ans *= combmod(n - 1 + count, n - 1, MOD) % MOD;
        ans %= MOD;
      }
      count = 0;
    } else {
      count++;
      tmp /= iter;
    }
  }

  if (count != 0) {
    //ans0 = fact(n+count-1);
    //ans2 = fact(count);
    // ans0 = fact_m(count + n - 1, count);
    // ans *= ans0/ans1 % aa;
    // ans = ans % aa;
    ans *= combmod(n - 1 + count, n - 1, MOD) % MOD;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
