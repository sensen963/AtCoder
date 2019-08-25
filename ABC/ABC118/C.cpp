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

ll gcd(ll a, ll b){
    if (a < b) {
        ll tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    ll tmp, ans;

    REP(i, N){
        cin >> tmp;
        if (i == 0) ans = tmp;
        else ans = gcd(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}