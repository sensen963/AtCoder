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

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
ll MOD = pow(10, 9) + 7;

int getX(ll num, int d){
    int tmp = num >> d;
    return (tmp % 2);
}
ll powmod(ll a, ll p, ll MOD) {
	ll ans = 1;
	ll mul = a;
	for (; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
		if ((p & 1) == 1)ans = (ans * mul) % MOD;
	}
	return ans;
}

int main() {

    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    ll ans = 0;
    REP(i, 60){
        ll tmp0 = 0, tmp1 = 0;
        for(auto iter : A){
            int tmp = getX(iter, i);
            tmp == 0 ? tmp0++ : tmp1++;
        }
        ll x = powmod(2, i, MOD);
        x = (x * tmp0) % MOD;
        x = (x * tmp1) % MOD;
        ans = (ans + x) % MOD;
    }
    cout << ans << endl;

    return 0;
}