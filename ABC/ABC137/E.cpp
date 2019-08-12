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
typedef pair<ll, ll> Pll;

#define EPS (1e-7)
#define INF (1e14)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

struct edge{
    ll from, to, cost;
};

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<edge> E(M);
    REP(i, M) {
        cin >> E[i].from >> E[i].to >> E[i].cost;
        E[i].from--;
        E[i].to--;
        E[i].cost = -1 * (E[i].cost - P);
    }

    vector<ll> G(N, INF);

    G[0] = 0;
    bool update = true;
    int j = 0;
    ll tmp = 0;
    while(update){
        update = false;
        if (j == N - 1){
            tmp = G[N - 1];
        }
        if (j == 2 * N){
            if (G[N - 1] >= tmp) break;
            cout << "-1" << endl;
            return 0;
        }
        REP(i, M){
            auto e = E[i];
            if (G[e.from] != INF && G[e.to] > G[e.from] + e.cost){
                if (j < N - 1) G[e.to] = G[e.from] + e.cost;
                else G[e.to] = -INF;
                update = true;
            }
        }
        j++;
    }
    ll ans = G[N - 1] > 0 ? 0 : -G[N - 1];
    //REP(i, N) cout << G[i] << endl;
    cout << ans << endl;

    return 0;
}
