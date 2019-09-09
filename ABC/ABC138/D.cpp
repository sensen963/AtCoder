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

void Flow(vector<set<ll>>& tree, vector<ll>& flow, ll parent, ll child){
    for(auto tmp : tree[child]){
        if (tmp != parent) {
            flow[tmp] += flow[child];
            Flow(tree, flow, child, tmp);
        }
    }
}

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<set<ll>> A(N);
    ll a, b;
    REP(i, N - 1){
        cin >> a >> b;
        A[a - 1].insert(b - 1);
        A[b - 1].insert(a - 1);
    }
    //cout << "Hi" << endl;

    vector<ll> flow(N, 0);
    REP(i, Q){
        cin >> a >> b;
        flow[a - 1] += b;
    }
    /*
    //cout << "Hi" << endl;
    vector<ll> ans(N, 0);
    REP(i, N){
        ans[i] += flow[i];
        for(auto tmp : A[i]){
            flow[tmp] += flow[i];
            //cout << "Hi" << endl;

        }
        cout << ans[i] << " ";
    }
    cout << endl;
*/

    Flow(A, flow, -1, 0);
    REP(i, N) cout << flow[i] << " ";
    cout << endl;
    return 0;
}
