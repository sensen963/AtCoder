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
typedef long long int ll;#include <iostream>
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

    ll H, W, D;
    cin >> H >> W >> D;
    ll tmp;
    vector<P> A(H*W+1); 
    REP(i, H) REP(j, W){
        cin >> tmp;
        A[tmp] = P(i+1, j+1);
    }
    vector<ll> S(H*W+1, 0);
    rep(i, D+1, H*W+1){
        S[i] = S[i-D] + abs(A[i-D].first - A[i].first) + abs(A[i-D].second - A[i].second);
    }
    ll Q;
    cin >> Q;
    vector<ll> L(Q), R(Q);
    REP(i, Q) cin >> L[i] >> R[i];

    REP(i, Q) cout << (S[R[i]] - S[L[i]]) << endl; 


    return 0;
}

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    return 0;
}