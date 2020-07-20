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

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<ll> C(N);
    vector<vector<ll>> A(N, vector<ll>(M));
    REP(i, N){
        cin >> C[i];
        REP(j, M) cin >> A[i][j];
    }
    ll ans = 1e9;
    REP(i, pow(2, N)){
        ll cost = 0;
        vector<ll> tmp(M, 0);
        REP(j, N){
            if ((i >> j) % 2 == 1) {
                REP(k, M) tmp[k] += A[j][k];
                cost += C[j];
            }
        }
        bool f = true;
        REP(j, M){
            if (tmp[j] < X) f = false;
        }
        if (f) ans = min(ans, cost);
    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
    return 0;
}