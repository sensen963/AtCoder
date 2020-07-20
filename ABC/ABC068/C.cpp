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
    int N, M;
    cin >> N >> M;
    int a, b;
    vector<set<int>> v(N);
    REP(i, M){
        cin >> a >> b;
        a--;
        b--;
        v[a].insert(b);
        v[b].insert(a);
    }
    REP(i, N){
        if (v[0].find(i) != v[0].end() && v[N-1].find(i) != v[N-1].end()){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}