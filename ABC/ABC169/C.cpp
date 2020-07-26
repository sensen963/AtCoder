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

    ll N;
    cin >> N;
    ll ans = 1;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
        if (A[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    REP(i, N){
        ll pre = ans;
        
        if (A[i] > (ll)1e18 / ans){
            cout << -1 << endl;
            return 0;
        }
        ans *= A[i];
    }
    //cout << (ll)1e18 << endl;
    cout << ans << endl;

    return 0;
}