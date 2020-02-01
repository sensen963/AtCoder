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

    ll H, N;
    cin >> H >> N;
    vector<ll> A(N), B(N);
    int tmp = 0;
    REP(i, N){
        cin >> A[i] >> B[i];
        tmp = max(tmp, A[i]);
    }
    vector<ll> res(H+tmp+1, 1e10);

    res[0] = 0;
    REP(i, N){
        REP(j, H) res[j+A[i]] = min(res[j+A[i]], res[j]+B[i]);
    }
    ll ans = 1e9;
    for(int i = H; i < H + tmp + 1; i++) ans = min(ans, res[i]);
    cout << ans << endl;

    return 0;
}
