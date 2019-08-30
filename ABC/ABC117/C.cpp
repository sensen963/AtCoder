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

    ll N, M;
    cin >> N >> M;
    vector<ll> x(M), red(M - 1);
    REP(i, M) cin >> x[i];
    sort(x.begin(), x.end());
    REP(i, M - 1) red[i] = x[i + 1] - x[i];
    sort(red.begin(), red.end());
    //cout << "Hi" << endl;
    ll sum = 0;
    if (M > N) REP(i, M - N) sum += red[i];
    cout << sum << endl;

    return 0;
}