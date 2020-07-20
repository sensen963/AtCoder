
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
    ll s;
    ll t;
    ll c;
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
    vector<con> v(N);
    REP(i, N) cin >> v[i].s >> v[i].t >> v[i].c;
    sort(v.begin(), v.end(), [](con& a, con& b){
        if (a.c == b.c) return (a.s < b.s);
        else return (a.c < b.c);
    });
    vector<P> e;
    REP(i, N){
        if (i < N - 1 && v[i].c == v[i+1].c && v[i].t == v[i+1].s){
            e.push_back(P(v[i].s, 1));
            e.push_back(P(v[i+1].t + 1, 0));
            i++;
        }else{
            e.push_back(P(v[i].s, 1));
            e.push_back(P(v[i].t + 1, 0));
        }
    }
    sort(e.begin(), e.end(), [](P& a, P& b){return a.first < b.first;});

    ll ans = 0, tmp = 0;
    REP(i, e.size()){
        if (e[i].second != 0) tmp++;
        else tmp--;
        if (i == e.size() - 1 || e[i].first != e[i+1].first) ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}

