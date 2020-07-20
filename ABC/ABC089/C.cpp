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
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    int N;
    cin >> N;
    vector<ll> s(5, 0);
    string ss;
    REP(i, N){
        cin >> ss;
        if (ss[0] == 'M') s[0]++;
        else if (ss[0] == 'A') s[1]++;
        else if (ss[0] == 'R') s[2]++;
        else if (ss[0] == 'C') s[3]++;
        else if (ss[0] == 'H') s[4]++;
    }

    ll ans = 0;
    ans += s[0] * s[1] * (s[2] + s[3] + s[4]);
    ans += s[0] * s[2] * (s[3] + s[4]);
    ans += s[0] * s[3] * s[4];
    ans += s[1] * s[2] * (s[3] + s[4]);
    ans += s[1] * s[3] * s[4];
    ans += s[2] * s[3] * s[4];

    cout << ans <<endl;

    return 0;
}