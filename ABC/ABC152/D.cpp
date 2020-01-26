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

    ll N;
    cin >> N;
    vector<vector<ll>> v(10, vector<ll>(10, 0));

    REP(i, N+1){
        if (i == 0) continue;
        int a = i % 10;
        if (a == 0) continue;
        int b = i;
        while(b >= 10) b /= 10;
        v[a][b]++;
    }
    ll ans = 0;
    for(int i = 1; i <= 9; i++) for(int j = 1; j <= 9; j++){
        ans += v[i][j] * v[j][i];
    }
    cout << ans << endl;
    return 0;
}
