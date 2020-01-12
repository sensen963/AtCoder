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


int main() {
    const ll MOD = 1e9 + 7;
    ll N;
    cin >> N;
    vector<ll> x(N);
    REP(i, N) cin >> x[i];
    vector<ll> d(N-1);
    REP(i, N-1) {
        d[i] = x[N-i-1] - x[N-i-2];
        //cout << d[i] << endl;
    }

    vector<ll> S(N, 0);
    REP(i, N){
        if (i == 0) continue;
        S[i] = (S[i-1] * i) % MOD;
        ll tmp = 0;
        for(int j = 1; j <= i; j++){
            ll tmp1 = (j * d[i-j]) % MOD;
            tmp = (tmp + tmp1) % MOD;
        }
        if (i > 1) for(int j = 1; j <= i-1; j++) tmp = (tmp * j) % MOD;
        S[i] = (S[i] + tmp) % MOD;
        cout << i << " " << S[i] << endl;
    }

    cout << S[N-1] << endl;

    return 0;
}