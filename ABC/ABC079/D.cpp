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

    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> c(10, vector<ll>(10));
    REP(i, 10)REP(j, 10) cin >> c[i][j];
    vector<vector<ll>> A(H, vector<ll>(W));
    REP(i, H) REP(j, W) cin >> A[i][j];
    REP(i, 10) REP(j, 10) REP(k, 10) c[j][k] = min(c[j][k], c[j][i] + c[i][k]);

    ll ans = 0;
    REP(i, H) REP(j, W) ans += A[i][j] == -1 ? 0 : c[A[i][j]][1];
    cout << ans << endl;

    return 0;
}