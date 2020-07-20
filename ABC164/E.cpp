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

struct Data{
    ll v;
    ll m;
    ll t;
    Data(ll v, ll m, ll t):v(v), m(m), t(t){}
    bool operator<(const Data& a) const{
        return t > a.t;
    }
};
struct edge{
    ll to, rate, time;
    edge(ll to, ll rate, ll time):to(to), rate(rate), time(time){}
};

int main() {
    ll N, M, S;
    cin >> N >> M >> S;
    ll tmp1, tmp2, a, b;
    vector<vector<edge>> e(N);
    REP(i, M){
        cin >> tmp1 >> tmp2 >> a >> b;
        tmp1--;
        tmp2--;
        e[tmp1].push_back(edge(tmp2, a, b));
        e[tmp2].push_back(edge(tmp1, a, b));
    }
        //cout << "Hi" << endl;
    vector<P> convert(N);
    REP(i, N){
        cin >> a >> b;
        convert[i] = P(a, b);
    }
    vector<vector<ll>> dp(51, vector<ll>(2505, INF));
    priority_queue<Data> q;
    q.push(Data(0, min(2504, S), 0));

    while(!q.empty()){
        Data hoge = q.top();
        q.pop();
        if (hoge.t < dp[hoge.v][hoge.m]){
            dp[hoge.v][hoge.m] = hoge.t;
            
            if (hoge.m + convert[hoge.v].first < 2501)q.push(Data(hoge.v, hoge.m + convert[hoge.v].first, hoge.t + convert[hoge.v].second));
            for(auto e: e[hoge.v]){
                if (hoge.m - e.rate >= 0 && hoge.t + e.time < dp[e.to][hoge.m - e.rate]) q.push(Data(e.to, hoge.m - e.rate, hoge.t + e.time));
            }
        }
    }

    REP(i, N-1){
        ll tmp = INF;
        REP(j, 2505) tmp = min(tmp, dp[i+1][j]);
        cout << tmp << endl;
    }



    return 0;
}
