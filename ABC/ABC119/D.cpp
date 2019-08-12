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
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B), x(Q);
    REP(i, A) cin >> s[i];
    REP(i, B) cin >> t[i];
    REP(i, Q) cin >> x[i];

    ll s1, s2, t1, t2;
    REP(i, Q){
        auto s_tmp = lower_bound(s.begin(), s.end(), x[i]);
        auto t_tmp = lower_bound(t.begin(), t.end(), x[i]);
        if (s_tmp == s.end()) {
            s1 = *(s.end() - 1);
            s2 = INF;
        } else if (s_tmp == s.begin()){
            s1 = -INF;
            s2 = *s.begin();
        } else{
            s1 = *(s_tmp - 1);
            s2 = *s_tmp;
        }
        if (t_tmp == t.end()) {
            t1 = *(t.end() - 1);
            t2 = INF;
        } else if (t_tmp == t.begin()){
            t1 = -INF;
            t2 = *t.begin();
        } else{
            t1 = *(t_tmp - 1);
            t2 = *t_tmp;
        }
        //cout << "s1: " << s1 << " s2:" << s2 << endl;
        //cout << "t1: " << t1 << " t2:" << t2 << endl;
        ll tmp = INF;
        tmp = min(tmp, max(s2, t2) - x[i]);
        tmp = min(tmp, x[i] - min(s1, t1));
        tmp = min(tmp, 2 * s2 - x[i] - t1);
        tmp = min(tmp, 2 * t2 - x[i] - s1);
        tmp = min(tmp, t2 + x[i] - 2 * s1);
        tmp = min(tmp, s2 + x[i] - 2 * t1);
        cout << tmp << endl;
    }

    return 0;
}
