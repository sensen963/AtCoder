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
#define INF 1e9
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    REP(i, R) {
        cin >> r[i];
        r[i]--;
    }
    ll A, B, C;
    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    REP(i, M){
        cin >> A >> B >> C;
        A--;
        B--;
        dp[A][B] = C;
        dp[B][A] = C;
    }
    REP(k, N) REP(i, N) REP(j, N){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
    sort(r.begin(), r.end());
    ll ans = INF;
    do{
        ll tmp = 0;
        REP(i, R-1) tmp += dp[r[i]][r[i+1]];
        ans = min(ans, tmp);

    }while(next_permutation(r.begin(), r.end()));
    cout << ans << endl;



    return 0;
}