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

ll MOD = pow(10, 9) + 7;

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
    vector<ll> C(N);
    REP(i, N) cin >> C[i];

    sort(C.begin(), C.end(), greater<ll>());

    ll tmp = powmod(2, N - 1, MOD);
    ll tmp2 = powmod(2, N - 2, MOD);

    //cout << tmp << " " << tmp2 << endl;
    ll ans = 0;
    ll hoge = tmp, hoge2;
    REP(i, N){
        hoge2 = (hoge * C[i]) % MOD;
        ans = (ans + hoge2) % MOD;
        hoge = (hoge + tmp2) % MOD;
    }

    //cout << ans << endl;
    tmp = (tmp * 2) % MOD;
    ans = (ans * tmp) % MOD;

    cout << ans << endl;




    return 0;
}