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
struct edge{
    ll l;
    ll from, to;
    edge(ll l, ll from, ll to):l(l), from(from), to(to){}
};
int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    vector<vector<ll>> C(N, vector<ll>(N, -1));
    REP(i, N)REP(j, N) cin >> A[i][j];
    REP(i, N) C[i][i] = 0;
    vector<edge> v;
    REP(i, N) for(ll j = 0; j < i; j++) v.push_back(edge(A[i][j], j, i));
    sort(v.begin(), v.end(), [](edge& a, edge& b){return a.l < b.l;});
    ll ans = 0;
    REP(i, v.size()){
        ll from = v[i].from;
        ll to = v[i].to;
        bool done = false;
        REP(j, N){
            if (C[from][j] > 0 && C[j][to] > 0){
                if (C[from][j] + C[j][to] < v[i].l){
                    cout << -1 << endl;
                    return 0;
                }
                if (C[from][j] + C[j][to] == v[i].l){
                    C[from][to] = v[i].l;
                    C[to][from] = v[i].l;
                    done = true;
                    break;
                }
            }
        }
        if (done) continue;
        C[from][to] = v[i].l;
        C[to][from] = v[i].l;
        ans += v[i].l;
    }
    cout << ans << endl;


    return 0;
}
