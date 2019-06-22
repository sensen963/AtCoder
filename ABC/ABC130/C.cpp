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
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
  int W, H, x, y;
  cin >> W >> H >> x >> y;

  int is = (2 * x == W && 2 * y == H ) ? 1 : 0;

  double ans = (double) W * (double) H / 2.0;

  cout << ans << " " << is << endl; 


}
