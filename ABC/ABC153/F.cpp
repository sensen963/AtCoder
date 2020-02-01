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
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)

// T have +-*/ and 0
template<class T> class bit {
public:
    vector<T> dat;
    ll N;

    bit(){}
    bit(ll N) : N(N) { dat.assign(N,0); }
    // sum [0,i)
    T sum(ll i){
        ll ret = 0;
        for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
        return ret;
    }
    // sum [i,j)
    T sum(ll i, ll j) { return sum(j) - sum(i); }
    // add x to i
    void add(ll i, T x) { for(; i < N; i|=i+1) dat[i] += x; }
};


int main() {
    ll N, D, A;
    cin >> N >> D >> A;

    vector<P> v(N);
    REP(i, N) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [](P& a, P& b){return a.first < b.first;});

    D = D*2;

    vector<ll> t(N);
    ll tmp = 0;
    REP(i, N){
        if (i == 0){
            t[i] = i;
            continue;
        }
        while(v[tmp].first < v[i].first - D) tmp++;
        t[i] = tmp;
    }
    bit<ll> tree = bit<ll>((ll)N);
    REP(i, N){
        ll res = v[i].second - tree.sum(t[i], i) * A;
        if (res <= 0) continue;
        res = res % A == 0 ? res / A : res / A + 1;
        tree.add(i, res);
    }

    cout << tree.sum(N) << endl;




    return 0;
}
