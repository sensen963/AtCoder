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

int dfs(ll i, int c){
    //cout << "dfs form" << i << endl;
    if (color[i] == 0){
        color[i] = c;
        for( auto tmp : G[i]){
            if (color[tmp.first] == 0){
                if (tmp.second % 2 == 0) dfs(tmp.first, c);
                else dfs(tmp.first, -c);
            }
        }
        return 1;
    }
    return 0;
}

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, M){
        int j, k, l;
        cin >> j >> k >> l;
        j--;
        k--;
        G[j].push_back(P(k, l));
        G[k].push_back(P(j, l));
    }
    int count = 0;
    REP(i, N){
        if(color[i] == 0){
            dfs(i, 1);
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
