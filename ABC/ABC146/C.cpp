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

    for(ll i = 1; i < 11; i++){
        ll tmp = (X - B * i) / A;
        //cout << i << ": " << tmp <<endl;
        if (i == 10 && tmp >= pow(10, 9)) ans = powl(10, 9);
        if (i < 10 && powl(10, i - 1) <= tmp && tmp < powl(10, i)) ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
