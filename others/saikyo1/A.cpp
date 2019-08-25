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

    int M, D;
    cin >> M >> D;
    ll ans = 0;
    for(int m = 1; m <= M; m++)for(int d = 1; d <= D; d++){
        int a = d / 10;
        int b = d % 10;
        if (a >= 2 && b >= 2 && a * b == m) ans++;
    }
    cout << ans << endl;


    return 0;
}