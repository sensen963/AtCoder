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
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    int N;
    cin >> N;

    vector<vector<int>> dp(2, vector<int>(N, 0)), a(2, vector<int>(N, 0));
    REP(i, 2) REP(j, N) cin >> a[i][j];

    dp[0][0] = a[0][0];
    dp[1][0] = a[0][0] + a[1][0];
    REP(i, 2) rep(j, 1, N){
        if (i == 0) dp[i][j] = dp[i][j - 1] + a[i][j];
        else dp[i][j] = max(dp[i-1][j], dp[i][j - 1]) + a[i][j];  
    }

    cout << dp[1][N - 1] << endl;

    return 0;
}

