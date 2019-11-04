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
#define INF 1e16
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)


int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> a(M), c(M, 0);
    REP(i, M){
        int b;
        cin >> a[i] >> b;
        int tmp;
        REP(j, b){
            cin >> tmp;
            c[i] += pow(2, tmp - 1);
        }
    }
    //REP(i, M) cout << c[i] << endl;
    vector<vector<ll>> dp(M+1, vector<ll>(pow(2, N), INF));
    dp[0][0] = 0;
    REP(i, M){
        REP(j, pow(2, N)){
            ll tmp = j | c[i];
            //cout << i << " " << j << " " << tmp <<endl;
            //cout << dp[i][j] << endl;
            //cout << dp[i][tmp] << endl;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][tmp] = min(min(dp[i][tmp], dp[i][j] + a[i]),dp[i+1][tmp]);
            //cout << dp[i+1][j] << endl;
            //cout << dp[i+1][tmp] << endl;

        }
    }
    ll ans = dp[M][pow(2, N)-1] >= INF ? -1 : dp[M][pow(2, N)-1];
    cout << ans << endl;

    return 0;
}