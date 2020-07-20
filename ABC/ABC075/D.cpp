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

ll count(vector<P>& v, ll a, ll a1, ll b, ll b1){
    ll c = 0;
    for(auto p : v){
        if (a <= p.first && p.first <= a1 && b <= p.second && p.second <= b1) c++;
    }
    return c;
}

ll d_try(vector<P>& v, ll K, ll a, ll a1, ll b, ll b1){
    ll c = count(v, a, a1, b, b1);
    if (c >= K) return (a1 - a) * (b1 - b);
    return (ll)(4 * 1e18 + 100);
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<P> v(N);
    REP(i, N) cin >> v[i].first >> v[i].second;
    ll ans = 4 * (1e18) + 100;
    REP(i, N)REP(j, N)REP(k, N)REP(l, N){
        ll a = min(v[i].first, v[j].first);
        ll a1 = max(v[i].first, v[j].first);
        ll b = min(v[k].second, v[l].second);
        ll b1 = max(v[k].second, v[l].second);
        if (a == a1 && b == b1){
            ans = min(ans, d_try(v, K, a, a1+1, b, b1+1));
            ans = min(ans, d_try(v, K, a, a1+1, b-1, b1));
            ans = min(ans, d_try(v, K, a-1, a1, b, b1+1));
            ans = min(ans, d_try(v, K, a-1, a1, b-1, b1));
        }else if(a == a1){
            ans = min(ans, d_try(v, K, a, a1+1, b, b1));
            ans = min(ans, d_try(v, K, a-1, a1, b, b1));
        }else if (b == b1){
            ans = min(ans, d_try(v, K, a, a1, b, b1+1));
            ans = min(ans, d_try(v, K, a, a1, b-1, b1));
        }else{
            ans = min(ans, d_try(v, K, a, a1, b, b1));
        }

    }
    cout << ans << endl;
    return 0;
}
