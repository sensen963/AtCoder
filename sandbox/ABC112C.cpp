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

    int N;
    cin >> N;
    vector<vector<ll>> dp(N, vector<ll>(3));
    REP(i, N) cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

    REP(i, 101)REP(j, 101){
        ll h;
        REP(k, N) if (dp[k][2] > 0){
            h = dp[k][2] + abs(dp[k][0] - i) + abs(dp[k][1] - j);
            break;
        }
        bool flag = true;
        REP(k, N){
            if (max(h - abs(dp[k][0] - i) - abs(dp[k][1] - j), 0LL) != dp[k][2]){
                flag = false;
                break;
            }
        }
        if (flag){
            cout << i << " " << j << " " << h << endl;
            return 0;
        }
    } 

    return 0;
}