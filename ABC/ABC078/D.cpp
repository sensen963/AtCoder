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

    int N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];
    if (N == 1){
        cout << abs(W - a[0]) << endl;
        return 0;
    }

    cout << max(abs(a[N-2] - a[N-1]), abs(a[N-1] - W)) << endl;

    return 0;
}