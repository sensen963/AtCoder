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
typedef pair<ll, ll> P;
#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)


int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    REP(i, N) cin >> H[i];
    ll a, b;
    vector<vector<ll>> v(N);
    REP(i, M){
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    vector<bool> t(N, true);
    ll ans = 0;
    REP(i, N){
        if (!t[i]) continue;
        ll st = H[i];
        for(auto iter: v[i]) if (st <= H[iter]) t[i] = false;
    }
    REP(i, N) if(t[i]) ans++;
    cout << ans << endl;

    return 0;
}