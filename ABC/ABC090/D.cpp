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
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    ll N, K;
    cin >> N >> K;

    if (K == 0){
        cout << (N * N) << endl;
        return 0;
    }
    ll ans = 0;

    rep(i, K + 1, N + 1){
        ll tmp = ((N - K + 1) / i) * (i - K);
        ll tmp1 = min(((N - K  + 1) % i), i - K);
        ans += tmp + tmp1;
    }

    cout << ans << endl;

    return 0;
}