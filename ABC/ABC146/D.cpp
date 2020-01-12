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
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

vector<int> color(1e5+2, -1);
vector<vector<int>> V(1e5+2);
vector<P> E(1e5+2);

int side(int parent, int edge){
    return E[edge].first == parent ? E[edge].second : E[edge].first;
}

void rep(int parent, int edge){
    if (V[parent].size() == 1) return;
    int c = color[edge];
    int num = 0;
    REP(i, V[parent].size()){
        int e = V[parent][i];
        if (e != edge) {
            if (num == c) num++;
            color[e] = num;
            num++;
            rep(side(parent, e), e);
        }
    }      
    return;
}

int main() {
    int N;
    cin >> N;
    int a, b;
    REP(i, N-1) {
        cin >> a >> b;
        a--;
        b--;
        E[i].first = a;
        E[i].second = b;
        V[a].push_back(i);
        V[b].push_back(i);
    }
    int root = 0, d = 0;
    REP(i, N){
        int tmp = V[i].size();
        if (d < tmp){
            root = i;
            d = tmp;
        }
    }
    
    REP(i, d) {
        int e = V[root][i];
        color[e] = i;
        rep(side(root, e), e);
    }
    cout << d << endl;
    REP(i, N-1) cout << (color[i] + 1) << endl;


    return 0;
}
