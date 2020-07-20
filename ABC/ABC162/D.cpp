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

    int N;
    cin >> N;
    string s;
    cin >> s;
    set<int> r, g, b;
    REP(i, N){
        if (s[i] == 'R') r.insert(i);
        if (s[i] == 'G') g.insert(i);
        if (s[i] == 'B') b.insert(i);
    }
    ll ans = 0;
    for(auto i : r) for(auto j: g){
        ll l = b.size();
        if ((i + j) % 2 == 0 && b.find((i+j)/2) != b.end()) l--;
        if (b.find(2*i-j) != b.end()) l--;
        if (b.find(2*j-i) != b.end()) l--;
        ans += l;
    }
    cout << ans << endl;

    return 0;
}

