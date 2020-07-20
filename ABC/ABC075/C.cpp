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

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> _size; // 属する連結成分の大きさ

    UnionFind(ll N) : par(N), _size(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        _size[ry] += _size[rx];
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll size(ll x){
        ll rx = root(x);
        return _size[rx];
    }
};

int main() {

    int N, M;
    cin >> N >> M;
    vector<P> v(M);
    REP(i, M){
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }
    ll ans = 0;
    REP(i, M){
        UnionFind u = UnionFind(N);
        REP(j, M){
            if (i != j) u.unite(v[j].first, v[j].second);
        }
        if (u.size(0) != N) ans++;
    }
    cout << ans << endl;

    return 0;
}
