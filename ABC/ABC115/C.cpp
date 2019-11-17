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
    vector<ll> h(N);
    REP(i, N) cin >> h[i];
    sort(h.begin(), h.end());
    //REP(i, N) cout << h[i] << " ";
    ll ans = INF;
    REP(i, N-K+1){
        ans = min(ans, h[i+K-1] - h[i]);
    }
    cout << ans << endl;

    return 0;
}