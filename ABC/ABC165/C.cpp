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

int N, M , Q;
vector<int> a, b, c, d;
int num;
ll dfs(vector<int>& v, ll m){
    ll ans = 0;
    //REP(i, v.size()) cout << v[i]<< " ";
        //cout << endl;
    if (v.size() < N){
        for(int i = m; i <= M; i++){
            v.push_back(i);
            ll tmp = dfs(v, i);
            ans = max(ans, tmp);
            v.pop_back();
        }
    }
    else{
        num++;
        //REP(i, N) cout << v[i]<< " ";
        //cout << endl;
        //cout << num << endl;
        REP(i, Q){
            if (v[b[i] - 1] - v[a[i] - 1] == c[i]) ans += d[i];
        }
    }
    return ans;
    
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    REP(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> v;
    num = 0;
    cout << dfs(v, 1) << endl;
    //cout << num << endl;
    return 0;
}