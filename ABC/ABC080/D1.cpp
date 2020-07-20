
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

struct con{
    ll t;
    ll c;
    ll s;
    con(ll i, ll j, ll k){
        t = i;
        c = j;
        s = k;
    }
};

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, init, n) for(ll i = init; i <(ll)(n); i++)

int main() {

    ll N, C;
    cin >> N >> C;
    vector<con> v;
    ll i, j, k;
    REP(l, N) {
        cin >> i >> j >> k;
        v.push_back(con(i, k, 1));
        v.push_back(con(j, k, -1));
    }

    sort(v.begin(), v.end(), [](con& a, con& b){
        if (a.c == b.c) return (a.t == b.t) ? (a.s > b.s) : (a.t < b.t);
        else return (a.c < b.c);
    });
    REP(i, v.size()){
        if (i < v.size() - 1 && v[i].t == v[i+1].t && v[i].c == v[i+1].c){
            v[i].s = 0;
            v[i+1].s=0;
        }else if (v[i].s == -1) v[i].t++;
    }
    sort(v.begin(), v.end(), [](con& a, con& b){
        return (a.t < b.t);
    });

    ll ans = 0, tmp = 0;
    REP(i, v.size()){
        tmp += v[i].s;
        if (i == v.size() - 1 || v[i].t != v[i+1].t) ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}

