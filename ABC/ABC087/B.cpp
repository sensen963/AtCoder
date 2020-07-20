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

    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ans = 0;
    REP(i, a+1) REP(j, b+1) REP(k, c+1){
        int tmp = 500 * i + 100 * j + 50 * k;
        if (x == tmp) ans++;
    }

    cout << ans << endl;


    return 0;
}

