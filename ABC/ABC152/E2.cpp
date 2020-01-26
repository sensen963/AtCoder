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
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))
#define NM 1e6+5
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)

vector<P> setpf(ll x){
    vector<P> v;

    ll ret = 0;
    for(ll i = 2; i * i <= x; i++) {
        ret = 0;
    while(x % i == 0) {
        ret++;
        x /= i;
        }
        if (ret > 0) v.push_back(P(i, ret));
    }
    if(x != 1) v.push_back(P(x, 1));
    return v;

}

vector<P> LCM(vector<P> a, vector<P> b){
    vector<P> v; 
    auto i1 = a.begin();
    auto i2 = b.begin();
    ll ret = 0;
    while(i1 != a.end() || i2 != b.end()){
        ret = 0;
        if (i2 == b.end() || (i1 != a.end() && (*i1).first< (*i2).first)){
            ret = (*i1).second;
            v.push_back(P((*i1).first, ret));
            i1++;
        }else if(i1 == a.end() || (i2 != b.end() && (*i1).first > (*i2).first)){
            ret = (*i2).second;
            v.push_back(P((*i2).first, ret));
            i2++;
        }else{
            ret = max((*i1).second, (*i2).second);
            v.push_back(P((*i1).first, ret));
            i1++;
            i2++;
        }
    }
    return v;
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
    vector<vector<P>> pv(N+1);
    ll lcm = 1, g, inv = 0;
    REP(i, N){
        cin >> v[i];
        pv[i] = setpf(v[i]);
        if (i == 0) pv[N] = pv[0];
        else pv[N] = LCM(pv[i], pv[N]);
    }
    ll mul = 1;
    for(auto iter : pv[N]){
        ll tmp = powmod(iter.first, iter.second, MOD);
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
