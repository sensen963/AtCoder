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

    ll N, K;
    cin >> N >> K;
    vector<P> t(N);
    REP(i, N) cin >> t[i].first >> t[i].second;
    sort(t.begin(), t.end(), [](P a, P b){return a.second > b.second;});
    priority_queue<ll, vector<ll>, greater<ll>> red;
    set<ll> a;

    ll sum = 0;
    REP(i, K){
        sum += t[i].second;
        if (a.find(t[i].first) != a.end()) red.push(t[i].second);
        else a.insert(t[i].first);
    }
    ll tmp = sum + a.size() * a.size();
    for(int i = K; i < N; i++){
        if (a.find(t[i].first) == a.end() && a.size() != K){
            a.insert(t[i].first);
            sum -= red.top();
            sum += t[i].second;
            red.pop();
            tmp = max(tmp, sum + a.size() * a.size());
        }
    }
    cout << tmp << endl;



    return 0;
}