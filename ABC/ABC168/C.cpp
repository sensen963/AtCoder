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
#include <cmath>
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
    double A, B, H, M;
    cin >> A >> B >> H >> M;

    double rad = (60.0 * H - 11.0 * M) * 3.141592653589793 / 360.0 ;
    //cout << cos(rad) << endl;
    double c = A * A + B * B - 2.0 * A * B * cos(rad);
    c = sqrt(c);
    printf("%.10f\n", c);

    return 0;
}
