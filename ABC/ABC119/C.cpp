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


int main() {

    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> d(N, 0);
    REP(i, N) {
        cin >> d[i];
    }

    ll ans = INF;
    REP(i, pow(4, N)){
        vector<vector<ll>> a(4);
        ll tmp = i;
        REP(j, N){
            a[tmp % 4].push_back(d[j]);
            tmp /= 4;
        }
        if (a[0].size() == 0 || a[1].size() == 0 || a[2].size() == 0) continue;

        ll A_sum = accumulate(a[0].begin(), a[0].end(), 0LL);
        ll B_sum = accumulate(a[1].begin(), a[1].end(), 0LL);
        ll C_sum = accumulate(a[2].begin(), a[2].end(), 0LL);

        ll tans = abs(A - A_sum) + 10 * (a[0].size() - 1) + abs(B - B_sum) + 10 * (a[1].size() - 1) + abs(C - C_sum) + 10 * (a[2].size() - 1);
        ans = min(ans, tans);
    }

    cout << ans << endl;

    return 0;
}
