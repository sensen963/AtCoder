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

ll gcd(ll a, ll b){
    if (a < b) {
        ll tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0) return a;
    return gcd(b, a  % b);
}

int main() {
    ll N;
    cin >> N;

    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    vector<ll> r(N), l(N);
    REP(i, N){
        if (i == 0){
            l[0] = A[0];
            r[N - 1] = A[N - 1];
        }
        else{
            l[i] = gcd(l[i - 1], A[i]);
            r[N - 1 - i] = gcd(r[N -  i], A[N - 1 - i]);
        }
    }
    ll ans = 1;
    REP(i, N){
        if (i == 0) ans = max(ans, r[1]);
        else if (i == N - 1) ans = max(ans, l[N - 2]);
        else ans = max(ans, gcd(l[i - 1], r[i + 1]));
    }
    cout << ans << endl;
    //cout << gcd(21, 14) << endl;
    // REP(i, N) cout << r[i] << " ";
    // cout << endl;
    // REP(i, N) cout << l[i] << " ";

    return 0;
}