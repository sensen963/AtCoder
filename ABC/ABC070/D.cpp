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
    ll N;
    cin >> N;
    vector<vector<P>> V(N);
    ll a, b, c;
    REP(i, N-1){
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].push_back(P(b, c));
        V[b].push_back(P(a, c));
    }
    ll Q, K;
    cin >> Q >> K;
    K--;
    vector<P> x(Q);
    REP(i, Q) {
        cin >> x[i].first >> x[i].second;
        x[i].first--;
        x[i].second--;
    }

    vector<ll> d(N, INF);
    d[K] = 0;
    priority_queue<ll> q;
    q.push(K);
    while(q.size() > 0){
        ll e = q.top();
        q.pop();
        for(auto iter: V[e]) {
            if(d[iter.first] >= INF){
                d[iter.first] = min(d[iter.first], d[e] + iter.second);
                q.push(iter.first);
            }
        }

    }
    REP(i, Q){
        cout << (d[x[i].first] + d[x[i].second]) << endl;
    }


    return 0;
}