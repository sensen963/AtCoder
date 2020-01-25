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


int main() {

    const ll MOD = 1e9 + 7;
    ll H, W, K;
    cin >> H >> W >> K;
    vector<vector<ll>> v(H+1, vector<ll>(W, 0));
    v[0][0] = 1;

    vector<vector<ll>> a(W, vector<ll>(W, 0));
    vector<ll> tmp(W);
    bool is_suit;
    REP(i, 1<<(W-1)){
        is_suit = true;
        REP(j, W-1) tmp[j] = (i>>j) & 1;
        REP(j, W-2) if (tmp[j] == 1 && tmp[j+1] == 1) is_suit = false;
        if (!is_suit) continue;
        REP(j, W){
            if (j != W-1 && tmp[j] == 1) a[j][j+1]++;
            else if (j != 0 && tmp[j-1] == 1) a[j][j-1]++;
            else a[j][j]++;
        }
    }

    /*
    REP(i, W) {
        REP(j, W) cout << a[i][j];
        cout << endl;
    }
    
*/
   REP(i, H)REP(j, W){
       v[i+1][j] = (v[i+1][j] + (v[i][j] * a[j][j]) % MOD) % MOD;
       if (j != W-1) v[i+1][j+1] = (v[i+1][j+1] + (v[i][j] * a[j][j+1] % MOD)) % MOD;
       if (j != 0) v[i+1][j-1] = (v[i+1][j-1] + (v[i][j] * a[j][j-1] % MOD)) % MOD;
   }
   /*
    REP(i, H+1) {
        REP(j, W) cout << v[i][j];
        cout << endl;
    }
*/
   cout << v[H][K-1] << endl;

    return 0;
}