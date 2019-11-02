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
#include <math.h>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

    double a, b, x;
    cin >> a >> b >> x;

    double ans;
    if (a * a * b / 2.0 < x){
        ans = atan(2.0 * (a * a * b - x) / (a * a * a));

    }else if (a * a * b / 2.0 == x){
        ans = atan(b / a);
    }else{
        ans = atan(a * b * b / 2.0 / x);

    }
    ans = ans / M_PI * 180.0;

    //cout << ans << endl;
    printf("%.7f\n", ans);

    return 0;
}