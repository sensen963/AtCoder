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

    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> dp(3001, -1);
    vector<int> a{100*A, 100*B, C, D};
    dp[a[0]] = 0;
    dp[a[1]] = 0;
    REP(i, 4){
        REP(j, F + 1){
            if (i < 2 && dp[j] >= 0 && j + a[i] <= F) dp[j + a[i]] = 0;
            if (i >= 2 && dp[j] >= 0 && j + a[i] <= F && (100 + E) * (dp[j] + a[i]) <= E * (j + a[i]) && 
                dp[j + a[i]] < dp[j] + a[i]) dp[j + a[i]] = dp[j] + a[i];
        }
    }
    int tmp = min(a[0], a[1]), hoge = 0;
    double den = 0;
    rep(i, 1, F + 1){
        if (dp[i] >= 0 && dp[i] > (double)i * den){
            den = (double)dp[i]/(double)i;
            tmp = i;
            hoge = dp[i];
        }
    }
    cout << tmp << " " << hoge << endl;

    return 0;
}
