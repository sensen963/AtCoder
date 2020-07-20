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
#include <random>
#include <fstream>

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

std::random_device rd;

std::mt19937 mt(rd());


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
        if (mt() < 0.5) swap(rx, ry);
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
      //std::ifstream in("35.txt");
  //std::cin.rdbuf(in.rdbuf());

    ll N, M;
    cin >> N >> M;
    vector<vector<P>> e(N);
    UnionFind u = UnionFind(N);
    ll a, b, c;
    REP(i, M){
        cin >> a >> b >> c;
        a--;
        b--;
        e[a].push_back(P(b, c));
        e[b].push_back(P(a, -c));
        u.unite(b, a);
    }

    vector<ll> cnd;
    vector<ll> x(N);
    vector<bool> visited(N, false);
    REP(i, N) if(u.root(i) == i) {
        cnd.push_back(i);
        visited[i] = true;
    }
    REP(i, cnd.size()){
        queue<ll> next;
        next.push(cnd[i]);
        while(next.size() > 0){
            ll j = next.front();
            //cout << next.size() << endl;
            for(auto p : e[j]){
                if (!visited[p.first]){
                    x[p.first] = x[j] + p.second;
                    visited[p.first] = true;
                    next.push(p.first);
                }else{
                    if(x[p.first] != x[j] + p.second){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
            next.pop();
        }

    }

    cout << "Yes" << endl;

    return 0;
}

