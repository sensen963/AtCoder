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
    vector<ll> v(N), t(N);
    REP(i, N) cin >> t[i];
    REP(i, N) cin >> v[i];
    ll total = 0;
    REP(i, N) total += t[i];
    vector<ll> m(total+1);
    ll tmp = 0;
    REP(i, N){
        REP(j, t[i]){
            if (j == 0 && i != 0) m[tmp] = min(v[i], v[i-1]);
            else m[tmp] = v[i];
            tmp++;
        }
    }
    //REP(i, total+1) cout << i << " " << m[i] << endl;
    m[total] = 0;
    ll current = 0;
    for(ll i = total-1; i >= 0; i--){
        if (m[i] > current){
            m[i] = ++current;
        }
        else{
            current = m[i];
        }
    }
    //REP(i, total+1) cout << i << " " << m[i] << endl;
    current = 0;
    ll count = 0;
    vector<ll> act(total + 1);
    act[0] = 0;
    rep(i, 1, total+1){
        if(current < m[i]){
            act[i] = ++current;
        }else{
            if (current == m[i] && m[i-1] > act[i-1]) count++;
            act[i] = m[i];
            current = m[i];
        }
    }
    //REP(i, total+1) cout << i << " " << act[i] << endl;
    double ans = (double)count * 0.25;
    REP(i, total) ans += (double)(act[i] + act[i+1]) / 2.0;
    printf("%.4f\n", ans);


    return 0;
}