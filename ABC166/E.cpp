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

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    map<ll, ll> p, n;
    REP(i, N){
        p[i + A[i]]++;
        if (i - A[i] >= 0) n[i - A[i]]++;
    }
    ll ans = 0;
    for(auto iter = p.begin(); iter != p.end(); iter++){
        ll i = iter->first;
        ans += p[i] * n[i];
    
    }
    cout << ans << endl;


    return 0;
}