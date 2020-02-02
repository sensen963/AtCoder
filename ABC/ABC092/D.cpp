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
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    int a, b;
    cin >> a >> b;

    vector<vector<int>> m(100, vector<int>(100, 0));
    REP(i, 50)REP(j, 100) m[i][j] = 1;

    int a_tmp = 1, b_tmp = 1;
    REP(i, 50)REP(j, 100){
        if (i % 2 == 0 && j % 2 == 0 && a_tmp < a){
            m[i][j] = 0;
            a_tmp++;
        }
        if (a_tmp == a) break;
    }

    rep(i, 51, 100)REP(j, 100){
        if (i % 2 == 0 && j % 2 == 0 && b_tmp < b){
            m[i][j] = 1;
            b_tmp++;
        }
        if (b_tmp == b) break;
    }
    cout << 100 << " " << 100 << endl;
    REP(i, 100){
        REP(j, 100){
            if (m[i][j]) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
    return 0;
}
