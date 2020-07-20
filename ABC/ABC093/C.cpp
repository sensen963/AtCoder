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

    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());

    int tmp = a[2] * 2 - a[0] - a[1];
    int ans;
    if (tmp % 2 == 0) ans = tmp / 2;
    else ans = (tmp + 3) / 2;

    cout << ans << endl;

    return 0;
}
