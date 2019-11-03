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

    ll N, M, L;
    cin >> N >> M >> L;
    vector<vector<ll>> d(N, vector<ll>(N, INF));
    REP(i, N) d[i][i] = 0;
    ll a, b, c;
    REP(i, M){
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = c;
        d[b][a] = c;
    } 
    ll Q;
    cin >> Q;
    vector<ll> s(Q), t(Q);
    REP(i, Q) {
        cin >> s[i] >> t[i];
        s[i]--;
        t[i]--;
    }


    REP(k, N) REP(i, N) REP(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    vector<vector<ll>> d1(N, vector<ll>(N, INF));
    REP(i, N) REP(j, N) if (i != j && d[i][j] <= L) d1[i][j] = 1;
    REP(i, N) d1[i][i] = 0;
    REP(k, N) REP(i, N) REP(j, N) d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);

    REP(i, Q){
        int ans = d1[s[i]][t[i]] < INF ? d1[s[i]][t[i]] - 1 : -1;
        cout << ans << endl;
    }

    return 0;
}