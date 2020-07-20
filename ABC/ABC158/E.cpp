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
#include <time.h>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    ll N, P;
    cin >> N >> P;
    string s;
    cin >> s;

    ll ans = 0;
    if (P == 2 || P == 5){
        REP(i, N){
            if((s[i] - '0') % P == 0) ans += (i + 1);
        }
        cout << ans << endl;
        return 0;
    }
    vector<ll> M(P, 0);
    M[0]++;
    ll tmp = 0;
    ll k = 1;
    for(ll i = N - 1; i >= 0; i--){
        tmp = (tmp + (s[i] - '0') * k) % P;
        k = (k * 10) % P;
        M[tmp]++;
    }
    REP(i, P) ans += (M[i] * (M[i] - 1)) / 2;
    cout << ans << endl;
    return 0;
}
