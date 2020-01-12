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

int dfs(string s, ll N){
    if (stoll(s) > N) return 0;
    string t = "357";
    bool f3 = false, f5 = false, f7 = false;
    REP(i, s.size()) REP(j, 3){
        if (s[i] == '3') f3 = true;
        if (s[i] == '5') f5 = true;
        if (s[i] == '7') f7 = true;
    }
    int tmp = (f3 && f5 && f7) ? 1 : 0;
    return tmp + dfs(s + "3", N) + dfs(s + '5', N) + dfs(s + '7', N);
}

int main() {

    ll N;
    cin >> N;
    cout << dfs("0", N) << endl;

    return 0;
}