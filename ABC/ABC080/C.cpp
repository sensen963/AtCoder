
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

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, init, n) for(ll i = init; i <(ll)(n); i++)

int main() {

    int N;
    cin >> N;
    vector<vector<ll>> F(N, vector<ll>(10));
    vector<vector<ll>> P(N, vector<ll>(11));
    REP(i, N) REP(j, 10) cin >> F[i][j];
    REP(i, N) REP(j, 11) cin >> P[i][j];

    ll ans = -1e9;
    for(ll i = 1; i < (1<<10); i++){
        vector<ll> tmp(10);
        REP(j, 10) tmp[j] = (i >> j) & 1;
        //REP(j, 10) cout << tmp[j] << " ";
        //cout << endl;
        ll score = 0;
        REP(j, N){
            ll hoge = 0;
            REP(k, 10) hoge += F[j][k] * tmp[k];
            score += P[j][hoge];
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
    return 0;
}

