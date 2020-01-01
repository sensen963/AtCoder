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

    ll A, B, X;
    cin >> A >> B >> X;
    ll ans = 0;
    for (ll i = 1; i < 10; i++){
        ll tmp = (X - B * i) / A;
        if (tmp >= powl(10, i)) ans = max(ans, powl(10, i) -1);
        else if (powl(10, i - 1) <= tmp && tmp < powl(10, i)) ans = max(ans, tmp);
    }
    ll i = 9;
    if (X >= A * powl(10, i) + B * 10) ans = 1e9;
    cout << ans << endl;

    return 0;
}
