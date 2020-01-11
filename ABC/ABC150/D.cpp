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
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

ll gcd(ll a, ll b){
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll tmp = gcd(a, b);
    //cout << tmp << endl;
    tmp = a / tmp;
    tmp = tmp * b;
    return tmp;
}

int main() {

    ll N, M;
    cin >> N  >> M;

    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    ll c = 1;
    while(A[0] % c == 0) c *= 2;
    c /= 2;

    ll tmp = 1;
    REP(i, N){
        if (A[i] % c != 0 || A[i] % (2 * c) == 0){
            cout << 0 << endl;
            return 0;
        }
        tmp = lcm(tmp, A[i]);
        
        if (tmp > 2 * M){
            cout << 0 << endl;
            return 0;
        }
        
        //cout << tmp << endl;
    }
    ll ans = (M + tmp / 2) / tmp;
    
    cout << ans << endl;

    return 0;
}