
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

    ll N, K;
    cin >> N >> K;
    vector<ll> v(N+1, 0);
    ll tmp;
    REP(i, N){
        cin >> tmp;
        v[tmp]++;
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ans = 0;
    REP(i, K) ans += v[i];
    cout << (N - ans) << endl;

    return 0;
}

