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
    ll n;
    cin >> n;
    if (n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }

    ll i = 10;
    ll ans = 0;
    while(i <= n){
        ans += n / i;
        i *= 5;
    }
    cout << ans << endl;

    return 0;
}