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

    int n, d, x;
    cin >> n >> d >> x;
    vector<int> A(n);
    REP(i, n) cin >> A[i];
    int ans = x;
    for(int i = 1; i <= d; i++){
        REP(j, n) if ((i - 1) % A[j] == 0) ans++;
    }
    cout << ans << endl;

    return 0;
}
