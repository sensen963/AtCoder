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
    vector<double> s(N);
    double tmp;
    REP(i, N){
        cin >> tmp;
        s[i] = (1.0 + tmp) / 2.0;
    }

    double hoge = 0;
    double ans = 0;
    REP(i, K) hoge += s[i];
    ans = hoge;
    rep(i, K, N){
        hoge -= s[i - K];
        hoge += s[i];
        ans = max(ans, hoge);
    }

    //cout << ans << endl;
    printf("%.8f\n", ans);

    return 0;
}