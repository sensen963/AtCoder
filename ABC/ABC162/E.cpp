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
#include <fstream>
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

ll gcd(ll a, ll b){
    if (a > b) return gcd(b, a);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll MOD = pow(10, 9) + 7;

ll powmod(ll a, ll p, ll MOD) {
	ll ans = 1;
	ll mul = a;
	for (; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
		if ((p & 1) == 1)ans = (ans * mul) % MOD;
	}
	return ans;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> v(K+1, 0);
    for(ll i = K; i > 0; i--){
        ll tmp = K / i;
        ll hoge = powmod(tmp, N, MOD) % MOD;
        for(ll j = 2*i; j <= K; j+=i) hoge =  (hoge - v[j] + MOD) % MOD;
        v[i] = hoge;
    }
    ll ans = 0;
    REP(i, K+1) {
        ll tmp = (i * v[i]) % MOD;
        ans = (ans + tmp) % MOD;
    }
    cout << ans << endl;

    return 0;
}

