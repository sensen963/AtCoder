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

ll R, S, P;

ll getP(char c){
    if (c == 'r') return P;
    if (c == 's') return R;
    return S;
}

int main() {

    ll N, K;
    string T;
    cin >> N >> K;
    cin >> R >> S >> P;
    cin >> T;

    vector<ll> val(N, 0);
    ll ans = 0;
    REP(i, N){
        if (i < K){
            ans += getP(T[i]);
            val[i] = getP(T[i]);
        }
        else if(val[i - K] == 0 || T[i - K] != T[i]){
            ans += getP(T[i]);
            val[i] = getP(T[i]);
        }
    }
    cout << ans << endl;
    return 0;
}