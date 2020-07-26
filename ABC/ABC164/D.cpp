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
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    vector<ll> v(2020, 0);
    const ll MOD = 1e9 + 7;
    ll tmp = 1;
    v[0]++;
    ll hoge = 0;
    REP(i, s.size()){
        hoge = (tmp * (s[i] - '0') + hoge) % 2019;
        v[hoge]++;
        tmp = (tmp * 10) % 2019;
    }
    ll ans = 0;
    REP(i, 2019) ans += v[i] * (v[i] - 1) / 2;
    cout << ans << endl;
    return 0;
}
