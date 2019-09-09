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


int main() {
    string s, t;
    cin >> s >> t;
    ll N = s.size();
    map<char, vector<ll>> V;
    REP(i, N){
        V[s[i]].push_back(i);
    }
    ll count = 0;
    ll N1 = t.size();
    ll iter = -1;
    REP(i, N1){
        if(V.count(t[i]) == 0){
            cout << -1 << endl;
            return 0;
        }
        auto hoge = upper_bound(V[t[i]].begin(), V[t[i]].end(), iter);

        if (hoge == V[t[i]].end()){
            iter = V[t[i]][0];
            count++;
        }else iter = *hoge;
        //cout << iter << " " << count << endl;
    }

    cout << (count * N + iter + 1) << endl;
    return 0;
}
