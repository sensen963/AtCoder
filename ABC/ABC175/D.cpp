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

#define REP(i, n) for(int i = 0; i < (ll)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    ll N, K;
    cin >> N >> K;
    vector<ll> P(N), C(N);
    REP(i, N) {
        cin >> P[i];
        P[i]--;
    }
    REP(i, N) cin >> C[i];
    
    ll ans = -INF;
    REP(init, N){
        vector<ll> score(N, -INF);
        vector<ll> visited(N, -1);

        visited[init] = 0;
        ll from = init;
        ll to;
        REP(i, K){
            to = P[from];
            if (visited[to] >= 0) {
                ll interval = i + 1 - visited[to];
                ll diff = (to != init) ? score[from] + C[to] - score[to]:score[from] + C[to] ;
                if (diff <= 0) break;
                ll vonus = (((K - visited[to]) / interval) -1) * diff;
                ll res = (K - visited[to]) % interval;
                ll tmp = -INF;
                ll from1 = to;
                ll to1;
                REP(j, interval){
                    to1 = P[from1];
                    score[to1] += vonus;
                    from1 = to1;
                }
                i += (((K - visited[to]) / interval) -1) * interval;
                vector<ll> visited1(N, -1);
                visited = visited1;
            }
            if (i != 0) score[to] = score[from] + C[to];
            else score[to] = C[to];
            visited[to] = i + 1;
            from = to;
        }
        REP(i, N) ans = max(ans, score[i]);
    }
    cout << ans << endl;

    return 0;
}