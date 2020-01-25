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
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

    ll N;
    cin >> N;

    vector<ll> x(N), L(N);
    vector<P> p(N);
    REP(i, N) {
        cin >> x[i] >> L[i];
        p[i].first = x[i] - L[i];
        p[i].second = x[i] + L[i];
    }

    sort(p.begin(), p.end(), [](pair<ll, ll> x, pair<ll, ll> y) { return x.second < y.second;});

    //REP(i, N) cout << p[i].first << " " << p[i].second << endl;
    int ans = 0;
    ll tmp = p[0].second;
    REP(i, N){
        if (i == 0) continue;
        if (tmp <= p[i].first){
            tmp = p[i].second;
        }
        else ans++;
    }

    cout << (N-ans) << endl;
    return 0;
}
