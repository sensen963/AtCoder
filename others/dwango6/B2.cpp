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

int main() {
    const ll MOD = 1e9 + 7;
    ll N;
    cin >> N;
    vector<ll> x(N);
    REP(i, N) cin >> x[i];
    vector<ll> d(N-1);
    REP(i, N-1) {
        d[i] = (x[i+1] - x[i]) % MOD;
        //cout << d[i] << endl;
    }

    ll f = 1;
    for(ll i = 1; i < N; i++) f = (f * i) % MOD;

    vector<ll> C(N-1);
    ll tmp;
    ll ans = 0;
    C[0] = 1;
    REP(i, N-1){
        tmp = (f * modinv(i+1, MOD)) % MOD;
        //cout << tmp << endl;
        if (i != 0) C[i] = (C[i-1] + tmp) % MOD;
        else C[i] = tmp;
        //cout << (i+1) << " " << C[i] << endl;
        tmp = (C[i] * d[i]) % MOD;
        ans = (ans + tmp) % MOD;
    }
    
    cout << ans << endl;

    return 0;
}