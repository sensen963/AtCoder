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
  int n, t;
  cin >> n >> t;

  int c, ta;
  int tmp = -1;
  int tmp_min = INF;
  REP(i, n) {
    cin >> c >> ta;
    if (ta <= t && c < tmp_min) {
      tmp_min = c;
      tmp = 1;
    }
  }
  if (tmp < 0) {
    cout << "TLE" << endl;
  } else cout << tmp_min << endl;


  return 0;
}
