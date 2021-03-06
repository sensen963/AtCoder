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
#define rep(i, init, n) for(ll i = init; i <(ll)(n); i++)

int main() {

    ll N;
    cin >> N;
    ll a;
    map<ll, ll> m;
    REP(i, N){
        cin >> a;
        m[a]++;
    }
    ll ans = 0;
    for(auto iter : m){
        if (iter.first <= iter.second) ans += iter.second - iter.first;
        else ans += iter.second;
    }

    cout << ans << endl;


    return 0;
}