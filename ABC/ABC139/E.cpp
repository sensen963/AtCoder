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

ll dfs(vector<set<int>> a, int from, int count, set<int> visited){
    ll hoge = 0;
    if (visited.find(from) == visited.end()) visited.insert(from);
    else return 1e7;
    if (a[from].size() == 0) {
        //cout << "Hi " << a[from].size() << endl; 
        return count;
    }
    for(auto tmp : a[from]) hoge = max(hoge, dfs(a, tmp, count + 1, visited));
    return hoge;
}

int main() {
    int N;
    cin >> N;

    vector<set<int>> V(N * N + 1);
    set<int> begins;
    //REP(i, N) REP(j, N) if (i < j) begins.insert(i * N + j);

    int tmp, tmp1;
    REP(i, N) {
        REP(j, N - 1){
        cin >> tmp;
        tmp--;
        tmp = i < tmp ? (i * N + tmp) :  (tmp * N + i); 
        if (j == 0) begins.insert(tmp);
        if (j != 0 && begins.find(tmp) == begins.end()) begins.erase(tmp);
        if (j != 0) {
            V[tmp1].insert(tmp);
            //cout << tmp1 << " " << tmp << endl;
        }
        tmp1 = tmp;
        }
    }
    /*

    for(auto tmp : begins){
        cout << V[tmp].size();
        cout << tmp << ": ";
        for(auto hoge : V[tmp]) cout << hoge << " ";
        cout << endl;
    }
*/
    ll hoge, cc = -1;
    for(auto tmp : begins){
        set<int> visited;
        hoge = dfs(V, tmp, 1, visited);
        //cout << hoge << endl;
        if (hoge >= 1e6){
            cc = -1;
            break;
        }
        cc = max(cc, hoge);
    }
    cout << cc << endl;
    //for(auto tmp : begins) cout << tmp << endl;

    return 0;
}
