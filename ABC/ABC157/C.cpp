
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
    string ans(N, 'p');
    bool f = true;
    int a;
    char c;
    REP(i, M){
        cin >> a;
        cin >> c;
        a--;
        if (a == 0 && c == '0') f = false;
        else if (ans[a] == 'p' || ans[a] == c){
            ans[a] = c;
        }
        else f = false;
        
    }
    if (ans[0] == 'p') ans[0] = '1';
    rep(i,1, N) if (ans[i] == 'p') ans[i] = '0';
    if (f) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}

