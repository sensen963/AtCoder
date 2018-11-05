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
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define maxll(a, b) (a > b ? a : b)

int main() {
  int n;
  cin >> n;
  vector<int> xv(n), yv(n);
  vector<ll> hv(n);
  REP(i, n) {
    cin >> xv[i] >> yv[i] >> hv[i];
  }
  ll h;
  ll tmp;
  bool flag = true;
  int tmpx, tmpy;
  ll hoge;
  REP(cx, 101) {
    REP(cy, 101) {
      flag = true;
      REP(i, n) if (hv[i] > 0) tmp = hv[i] + abs(xv[i] - cx) + abs(yv[i] - cy);
      REP(i, n) {
        hoge = tmp - abs(xv[i] - cx) - abs(yv[i] - cy);
        //if (cx == 2 && cy == 2) cout << maxll(hoge, 0) << endl;
        if (hoge < 0) hoge = 0;
        if (hoge != hv[i]) flag = false;
      }
      //if (cx == 2 && cy == 2) cout << tmp;
      if (flag) {
        h = tmp;
        tmpx = cx;
        tmpy = cy;
      }
    }
  }
  cout << tmpx << " " << tmpy << " " << h << endl;

  return 0;
}
