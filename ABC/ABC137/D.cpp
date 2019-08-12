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
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

    ll N, M;
    cin >> N >> M;
    vector<P> v(N);
    REP(i, N) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](P a, P b){
        return (a.first < b.first);
    });
    //REP(i, N) cout << v[i].first << v[i].second << endl;
    priority_queue<int> q;
    int inde = 0;
    ll tmp = 0;
    REP(i, M + 1){
        while(inde < N && v[inde].first <= i) q.push(v[inde++].second);
        if (q.empty()) continue;
        tmp += q.top();      
        //cout << "added" << i << ":" << q.top() << endl;
        q.pop();
    }

    cout << tmp << endl;
    return 0;
}
