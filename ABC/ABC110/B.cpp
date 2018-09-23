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

  int n, m , x1, y1;
  cin >> n >> m >> x1 >> y1;

  vector<int> ax(n), ay(m);

  REP(i, n) cin >> ax[i];
  REP(i, m) cin >> ay[i];

  int bb = *min_element(ay.begin(), ay.end());
  int aa = *max_element(ax.begin(), ax.end());

  //cout << aa << bb << endl;
  aa = max(aa, x1);
  bb = min(bb, y1);

  //cout << aa << bb << endl;
  if (aa < bb) {
    cout << "No War" << endl;
  }else {
    cout << "War" << endl;
  }


  return 0;
}
