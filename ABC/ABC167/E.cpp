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

ll MOD = 998244353;

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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> powM(N), comb(N);
    powM[0] = 1;
    comb[0] = 1;
    REP(i, N-1){
        powM[i + 1] = (powM[i] * (M - 1)) % MOD;
        ll tmp = comb[i] * (N - i - 1) % MOD;
        comb[i + 1] = (tmp * modinv(i + 1, MOD)) % MOD;

    }
    ll ans = 0;
    REP(i, K+1){
        ll hoge = (M * powM[N - i - 1]) % MOD;
        hoge = (hoge * comb[i]) % MOD;
        ans = (ans + hoge) % MOD;
    }
    cout << ans << endl;

    return 0;
}