
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
typedef pair<ll ,ll> P;
#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    ll N;
    cin >> N;
    vector<ll> v(N);
    ll tmp = 0, iter;
    vector<P> ans;
    REP(i, N){
        cin >> v[i];
        if (tmp < abs(v[i])){
            tmp = abs(v[i]);
            iter = i;
        }
    }
    if (v[iter] > 0){
        REP(i, N-1){
            //if (v[i] <= v[i + 1]) continue;
            ans.push_back(P(iter, i + 1));
            ans.push_back(P(iter, i + 1));
            v[i+1] += 2 * v[iter];
            iter = i + 1;
            //REP(i, N) cout << v[i] << " ";
            //cout << endl;
        }
    }else{
        for(ll i = N - 1; i > 0; i--){
            //if (v[i-1] <= v[i]) continue;
            ans.push_back(P(iter, i - 1));
            ans.push_back(P(iter, i - 1));
            v[i-1] += 2 * v[iter];
            iter = i - 1;
             //           REP(i, N) cout << v[i] << " ";
            //cout << endl;
        }
        
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) cout << (ans[i].first + 1) << " " << (ans[i].second + 1) << endl;
    return 0;
}

