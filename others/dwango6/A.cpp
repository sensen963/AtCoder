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
    int N;
    cin >> N;
    vector<string> s(N);
    vector<int> t(N);
    REP(i, N) cin >> s[i] >> t[i];

    string x;
    cin >> x;

    int ans = 0;
    bool ok = false;
    REP(i, N){
        if (ok) ans += t[i];
        if (s[i] == x)ok = true;
        
    }

    cout << ans << endl;
    return 0;
}