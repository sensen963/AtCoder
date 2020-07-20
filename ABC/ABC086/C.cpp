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

    int N;
    cin >> N;
    int t = 0, x = 0, y = 0;
    int tt, xx, yy;
    bool flag = true;
    REP(i, N){
        cin >> tt >> xx >> yy;
        if (!flag) continue;
        int tmp = tt - t - abs(yy - y) - abs(xx - x);
        if (tmp < 0 || tmp % 2 != 0) {flag = false;}
    }
    string s = "Yes";
    if(!flag) s = "No";
    cout << s << endl;

    return 0;
}