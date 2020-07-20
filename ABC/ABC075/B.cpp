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
    int H, W;
    cin >> H >> W;
    vector<string> d(H+2);
    string tmp;
    rep(i, 1, H+1){
        cin >> tmp;
        d[i] = '.' + tmp + '.';
    }
    string tmp1(W+2, '.');
    d[0] = tmp1;
    d[H+1] = tmp1;
    vector<string> ans(H, string(W, '#'));
    REP(i, H)REP(j, W){
        int cnt = 0;
        if(d[i+1][j+1] == '#') continue;
        if(d[i][j] == '#') cnt++;
        if(d[i][j+1] == '#') cnt++;
        if(d[i][j+2] == '#') cnt++;
        if(d[i+1][j] == '#') cnt++;
        if(d[i+1][j+2] == '#') cnt++;
        if(d[i+2][j] == '#') cnt++;
        if(d[i+2][j+1] == '#') cnt++;
        if(d[i+2][j+2] == '#') cnt++;
        ans[i][j] = '0' + cnt;
    }
    REP(i, H) cout << ans[i] << endl;

    return 0;
}
