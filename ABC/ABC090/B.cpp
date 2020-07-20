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

bool rev(int a){
    string s1 = to_string(a);
    string s2;
    REP(i, s1.size()) s2 += s1[s1.size()-i-1];
    return (s1 == s2);
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    rep(i, a, b+1){
        if (rev(i)) ans++;
     }
    cout << ans << endl;
    return 0;
}