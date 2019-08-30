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

    double P;
    cin >> P;

    double x;
    x = 1.5 / log(2.0);
    x = 2.16404;
    //cout << x << endl;
    x = max(-1.0 * x * log(x / P), 0);
    double ans = P / pow(2.0, x / 1.5) + x;    

    printf("%.9f\n", ans);

    return 0;
}