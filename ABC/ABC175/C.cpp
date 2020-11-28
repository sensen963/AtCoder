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
    ll X, K, D;

    cin >> X >> K >> D;
    if (X < 0) X *= -1;
    
    if (X / D > K) {
        ll tmp = X - K * D;
        cout << abs(tmp) << endl;
        return 0;
    }
    ll mod = X % D;
    if (((X - mod) / D) % 2 == 0 ^ K % 2 == 1) cout << mod << endl;
    else cout << abs(mod - D) << endl;

    return 0;
}