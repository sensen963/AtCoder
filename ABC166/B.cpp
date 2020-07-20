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
    int N, K;
    cin >> N >> K;
    vector<int> d(K);
    vector<vector<int>> A(K, vector<int>(N));
    vector<bool> v(N, false);
    REP(i, K){
        cin >> d[i];
        REP(j, d[i]) {
            cin >> A[i][j];
            v[A[i][j]-1] = true;
        }
    }

    ll ans = 0;
    REP(i, N) if (!v[i]) ans++;
    cout << ans << endl;
    return 0;
}