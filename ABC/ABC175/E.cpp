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
    ll R, C, K;
    cin >> R >> C >> K;
    vector<vector<ll>> P(R, vector<ll>(C, 0));
    vector<ll> v(K);
    ll a, b;
    REP(i, K) {
        cin >> a >> b >> v[i];
        a--;b--;
        P[a][b] = v[i];
    }

    vector<vector<vector<ll>>> dp(R+2, vector<vector<ll>>(C+2, vector<ll>(4, 0)));
    REP(i, R) REP(j, C) REP(k, 4) {
        if (P[i][j] > 0 && k < 3) {
            dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + P[i][j]);
            dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k] + P[i][j]);
        }
        dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
        dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k]);
        
    }

    //ll ans = max(dp[R-1][C][0], max(dp[R-1][C][1], max(dp[R-1][C][2], dp[R-1][C][3])));
    ll ans = dp[R][C-1][0];
    cout << ans << endl;

    
    return 0;
}