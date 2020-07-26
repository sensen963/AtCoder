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
#include <fstream>
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

    ll N;
    cin >> N;
    ll n = N;
    set<ll> s;
    ll ans = 0;
    for(ll i = 2; i * i <= n; i++){
        ll tmp = 0;
        while(N % i == 0){
            tmp++;
            N /= i;
        }
        ll tmp1 = 1;
        while(tmp1 * (tmp1 + 1) / 2 <= tmp) tmp1++;
        ans += tmp1 - 1;

    }
    if (N != 1) ans++;
    cout << ans << endl;

    return 0;
}