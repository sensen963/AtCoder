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
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
    vector<int> a = {2,5,5,4,5,6,3,7,6};
    ll N, M;
    cin >> N >> M;
    vector<P> A(M);
    int argmin = 0;
    REP(i, M) {
        cin >> A[i].first;
        A[i].second = a[A[i].first - 1];
        if ((A[i].second == A[argmin].second && A[i].first > A[argmin].first) || A[i].second < A[argmin].second) argmin = i;
    }
    int std = A[argmin].first;
    int minc = A[argmin].second;

    sort(A.begin(), A.end(), [](P r, P l){
        return (r.first > l.first);
    });

    vector<ll> dp(N + 1, -1);
    dp[0] = 0;
    REP(i, N + 1){
        if (i == 0) continue;
        ll tmp1 = -1;
        for(auto tmp : A){
            if (i - tmp.second >= 0) if (dp[i - tmp.second] != -1) tmp1 = max(tmp1, dp[i - tmp.second] + 1);
        }
        dp[i] = tmp1;
    }
    //REP(i, N + 1)cout << dp[i] << endl;
    vector<int> s;
    ll red = N;
    REP(i, dp[N]){
        for(auto tmp : A){
            if (red - tmp.second >= 0) if (dp[red - tmp.second] == dp[red] - 1){
                s.push_back(tmp.first);
                red -= tmp.second;
                break;
            }
        }
    }

    REP(i, dp[N])cout << s[i];
    cout << endl;

    return 0;
}