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
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(ll N) : par(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) par[i] = i;
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
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main() {

  ll N;
  cin >> N;
  ll x, y;
  set<ll> array1, array2, array3;
  UnionFind UF(3 * 1e5);
  REP(i, N){
    cin >> x >> y;
    array1.insert(2 * x - 1);
    array2.insert(2 * y);
    UF.unite(2 * x - 1, 2 * y);
  }
  ll count = 0;
  map<ll, ll> map1;
  map<ll, ll> map2;
  for(auto i : array1){
    x = UF.root(i);
    map1[x]++;
    array3.insert(x);
  }
    //cout << "x:" << i << endl;
  for(auto j : array2){
    y = UF.root(j);
    map2[y]++;
    array3.insert(y);
  }
  for(auto i: array3) count += map1[i] * map2[i];

  cout << (count - N) << endl;
  return 0;
}
