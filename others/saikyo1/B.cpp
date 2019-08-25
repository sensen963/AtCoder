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

    ll ans = 0;
    const ll MOD = 1e9 + 7;
    ll tmp1, tmp2;
    ll K1 = K * (K + 1) / 2;
    K1 %= MOD;
    ll K2 = K * (K - 1) / 2;
    K2 %= MOD;
    REP(i, N){
        tmp1 = 0;
        tmp2 = 0;
        REP(j, N){
            if (i == j) continue;
            if (A[i] > A[j]){
                if (i < j) tmp1++;
                else tmp2++;
            }
        }
        
        tmp1 = (tmp1 * K1 )% MOD;
        tmp2 = (tmp2 * K2) % MOD;
        ans = (ans + tmp1) % MOD;
        ans = (ans + tmp2) % MOD;
    }
    cout << ans << endl;
    return 0;
}