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

    int N;cin >> N;

    vector<vector<string>> v(N);
    v[0].push_back("a");
    REP(i, N-1){
        for(auto s : v[i]){
            int sz = 0;
            REP(j, s.size()) sz = max(sz, s[j] - 'a');
            REP(j, sz+2) {
                char c = 'a' + j;
                string c1 = to_string(c);
                v[i+1].push_back(s + c);
            }
        }
    }
    REP(i, v[N-1].size()) cout << v[N-1][i] << endl;
 

    return 0;
}
