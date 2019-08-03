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

vector<vector<P>> G(1e5);
vector<int> color(1e5, 0);

bool dfs(ll i, int c){
    //cout << "dfs form" << i << endl;
    if (color[i] == 0){
        color[i] = c;
        for( auto tmp : G[i]){
            if (color[tmp.first] == 0){
                if (tmp.second % 2 == 0) dfs(tmp.first, c);
                else dfs(tmp.first, -c);
            }
        }
    }
    return true;
}

int main() {

    ll N;
    cin >> N;
    ll i, j, k;
    REP(l, N - 1){
        cin >> i >> j >> k;
        i--;
        j--;
        G[i].push_back(P(j, k));
        G[j].push_back(P(i, k));
    }
    //cout << "auau";
    REP(i, N) dfs(i, 1);
    int tmp;
    REP(i, N){
        
        if (color[i] == -1) tmp = 0;
        else tmp = 1;
        cout << tmp << endl;
    }

    return 0;
}
