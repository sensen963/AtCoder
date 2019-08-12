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
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

    int N;
    cin >> N;
    vector<string> vs(N);
    map<string, ll> m;
    REP(i, N) {
        cin >> vs[i];
        sort(vs[i].begin(), vs[i].end());
        if (m.find(vs[i]) == m.end()) m[vs[i]] = 1;
        else m[vs[i]]+=1;
    }   
    ll ans = 0;    
    for(auto tmp: m){
        ans += ((tmp.second - 1) * tmp.second) / 2;
    }
    cout << ans << endl;
    return 0;
}
