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
#define NM 1e6+5
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

class pf{
    public:
    vector<ll> v;
    vector<ll> keys;
};

pf setpf(ll x){
    pf p = pf();
    vector<ll> ret(NM, 0);

  for(ll i = 2; i * i <= x; i++) {
    while(x % i == 0) {
      ret[i]++;
      x /= i;
      if (p.keys.size() == 0 || *(p.keys.end()-1) != i) p.keys.push_back(i);
    }
  }
  if(x != 1) {ret[x] = 1; p.keys.push_back(x);}
  p.v = ret;
  return p;

}

pf LCM(pf a, pf b){
    pf p = pf();
    vector<ll> ret(NM, 0);
    auto i1 = a.keys.begin();
    auto i2 = b.keys.begin();
    while(i1 != a.keys.end() || i2 != b.keys.end()){
        if (*i1 == *i2){
            ret[*i1] = max(a.v[*i1], b.v[*i2]);
            p.keys.push_back(*i1);
            i1++;
            i2++;
        }else if (i2 == b.keys.end() || (i1 != a.keys.end() && *i1 < *i2)){
            ret[*i1] = a.v[*i1];
            p.keys.push_back(*i1);
            i1++;
        }else{
            ret[*i2] = b.v[*i2];
            p.keys.push_back(*i2);
            i2++;
        }
    }
    p.v = ret;
    return p;
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

ll powmod(ll a, ll p, ll MOD) {
	ll ans = 1;
	ll mul = a;
	for (; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
		if ((p & 1) == 1)ans = (ans * mul) % MOD;
	}
	return ans;
}

int main() {
    const ll MOD = 1e9 + 7;
    ll N;
    cin >> N;
    vector<ll> v(N);
    vector<pf> pv(N+1);
    ll lcm = 1, g, inv = 0;
    REP(i, N){
        cin >> v[i];
        pv[i] = setpf(v[i]);
        if (i == 0) pv[N] = pv[0];
        else pv[N] = LCM(pv[i], pv[N]);
    }
    ll mul = 1;
    for(auto iter : pv[N].keys){
        ll tmp = powmod(iter, pv[N].v[iter], MOD);
        mul = (mul * tmp) % MOD;
    }

    ll ans = 0;
    REP(i, N){
        inv = mul * modinv(v[i], MOD) % MOD;
        ans = (ans + inv) % MOD;
    }

    cout << ans << endl;


    return 0;
}
