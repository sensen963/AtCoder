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
    const ll mod = 1e9+7;

    ll a=1, b=1, c=8, d=0;
    rep(i, 1, N){
        ll aa = (((a * 9) % mod) + c) % mod;
        ll bb = (((b * 9) % mod) + c) % mod;
        ll cc = (c * 8) % mod;
        ll dd = (((((d * 10) % mod) + a) % mod) + b) % mod;
        a = aa;
        b = bb;
        c = cc;
        d = dd;
    }
    cout << d << endl;

    return 0;
}
