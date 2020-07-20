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

int sumd(int d){
    int s = 0;
    while(d > 0){
        s += d % 10;
        d /= 10;
    }
    return s;
}

int main() {

    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i, 1, n + 1){
        int tmp = sumd(i);
        if (a <= tmp && tmp <= b) ans += i;
    }

    cout << ans << endl;

    return 0;
}
