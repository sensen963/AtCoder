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
    int m = 1e5 + 1;
    vector<bool> is_prime(m, true);
    is_prime[0] = false;
    is_prime[1] = false;
    rep(i, 2, sqrt(m) + 1){
        if (!is_prime[i]) continue;
        for (int j = i * 2; j < m; j+=i) is_prime[j] = false;
    }

    vector<int> s(m, 0);
    rep(i, 1, m){
        s[i] = s[i - 1];
        if (is_prime[i] && is_prime[(i + 1) / 2]) s[i]++;
    }

    int Q;
    cin >> Q;
    int a, b;
    vector<int> ans(Q);
    REP(i, Q){
        cin >> a >> b;
        ans[i] = s[b] - s[a-1];
    }
    REP(i, Q) cout << ans[i] << endl;

    return 0;
}