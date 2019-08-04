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

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> _size; // 属する連結成分の大きさ

    UnionFind(int N) : par(N), _size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        _size[ry] += _size[rx];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x){
        int rx = root(x);
        return _size[rx];
    }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    REP(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    //cout << "auau" << endl;
    ll Nmax = N * (N - 1) / 2;

    vector<ll> d;
    ll tmp = 0;
    d.push_back(Nmax);
    //cout << "auau" << endl;
    UnionFind U = UnionFind(N);
    //cout << "auau" << endl;

    for (ll i = M - 1; i >= 1; i--){
        //REP(i, N) cout << U.root(i);
        //cout << endl;
        if (U.same(A[i], B[i]))  tmp = 0;
        else{
            int s1 = U.size(A[i]);
            int s2 = U.size(B[i]);
            U.unite(A[i], B[i]);
            tmp = s1 * s2;
            
            //cout << "from" << i << endl;
        }
        //cout << A[i] << B[i] << endl;
        //cout << i <<":" << tmp << endl;
        d.push_back(*(d.end() - 1) - tmp);
    }
    //cout << "auau" << endl;
    for (ll i = d.size() - 1; i >=0; i--) cout << d[i] << endl;

    return 0;
}
