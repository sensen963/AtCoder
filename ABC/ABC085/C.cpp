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

    ll N, Y;
    cin >> N >> Y;

    rep(i, 0, N + 1)rep(j, 0, N - i + 1){
        int k = N - i - j;
        ll tmp = i * 10000 + j * 5000 + k * 1000;
        if (tmp == Y){
            cout << i << " " << j << " " << k << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;

    return 0;
}