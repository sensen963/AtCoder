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
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    REP(i, A) cin >> p[i];
    REP(i, B) cin >> q[i];
    REP(i, C) cin >> r[i];
    sort(p.begin(), p.end(), std::greater<ll>());
    sort(q.begin(), q.end(), std::greater<ll>());
    sort(r.begin(), r.end(), std::greater<ll>());
    vector<ll> ps(A, p[0]), qs(B, q[0]), rs(C, r[0]);
    REP(i, A-1) ps[i+1] = ps[i] + p[i];
    REP(i, B-1) qs[i+1] = qs[i] + q[i];
    REP(i, C-1) rs[i+1] = rs[i] + r[i];

    vector<P> v(A+B+C);
    REP(i, A) v[i] = P(0, p[i]);
    REP(i, B) v[i+A] = P(1, q[i]);
    REP(i, C) v[i+A+B] = P(2, r[i]);
    sort(v.begin(), v.end(), [](P x, P y) { return x.second > y.second;});

    ll ans = 0;
    ll xcount = 0, ycount = 0, count = 0;
    ll i = 0, j = 0, k = 0;
    for(ll i = 0; count < X + Y; i++){
        auto tmp = v[i];
        if (tmp.first == 0 && xcount < X){
            xcount++;
            count++;
            ans += tmp.second;
        }else if (tmp.first == 1 && ycount < Y){
            ycount++;
            count++;
            ans += tmp.second;
        }else if (tmp.first == 2){
            count++;
            ans += tmp.second;
        }
    }
    cout << ans << endl;
    return 0;
}
