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

int main() {

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    vector<ll> S(N+1);
    S[0] = 0;
    REP(i, N)  S[i + 1] = (S[i] + A[i] - 1 )% K;
    //REP(i, N+1) cout << S[i] << " "; cout << endl;

    map<ll, ll> m;
    ll ans = 0;
    REP(i, min(N + 1, K)){
        m[S[i]]++;
    }
    REP(i, N+1){
        ll tmp = S[i];
        ans += m[tmp] - 1;
        //cout << tmp << " " << (m[tmp] - 1) << endl;
        m[tmp]--;
        if (i + K - 1 < N) m[S[i + K]]++;
    }
    cout << ans << endl;



    return 0;
}
