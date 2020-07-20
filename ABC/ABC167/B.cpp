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
    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    ll sum = 0;
    if (K >= 0) {
        sum += min(A, K);
        K -= A;
    }
    if (K >= 0) {
        K -= B;
    }
    if (K >= 0) {
        sum -= K;
    }
    cout << sum << endl;

    return 0;
}