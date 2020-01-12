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
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
    ll N, T;
    cin >> N >> T;

    vector<P> v(N);
    REP(i, N) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](P x, P y) { return x.first < y.first;});

    vector<vector<ll>> dp(N+1, vector<ll>(T+1, 0));

    ll mt = 0;
    REP(i, N)REP(j, T){
        if (j + v[i].first >= T) mt = max(mt, dp[i][j] + v[i].second);
        else dp[i+1][j+v[i].first] = max(dp[i+1][j+v[i].first], dp[i][j] + v[i].second);
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }
    //REP(i, N) cout << v[i].first << " " << v[i].second << endl;
    //REP(i, T) cout << dp[N][i] << " ";

    cout << mt << endl;

    

    return 0;
}