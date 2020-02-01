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


void dfs(vector<int>& d, vector<set<int>>& V,  int dist, int self){
    d[self] = dist;
    for(auto iter : V[self]){
        if (d[iter] == -1) dfs(d, V, dist + 1, iter);
    }
    return;
}
int main() {

    int N, v, u;
    cin >> N >> v >> u;
    v--;
    u--;
    vector<set<int>> V(N);
    int a, b;
    REP(i, N-1){
        cin >> a >> b;
        a--;
        b--;
        V[a].insert(b);
        V[b].insert(a);
    }

    if (V[v].size() == 1 && *(V[v].begin()) == u){
        cout << 0 << endl;
        return 0;
    }
    vector<int> d1(N, -1), d2(N, -1);

    dfs(d1, V, 0, v);
    dfs(d2, V, 0, u);

    int cand = 0;
    REP(i, N){ 
        if (d2[i] > cand && d1[i] <= d2[i]) cand = d2[i];
    }

    cout << (cand - 1) << endl;



    return 0;
}