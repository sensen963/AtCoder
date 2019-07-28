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


int main() {

  int N, M;
  cin >> N >> M;
  int l, r;
  int tmpl, tmpr;
  REP(i, M){
    cin >> l >> r;
    if (i == 0) {
      tmpl = l;
      tmpr = r;
    }else{
      tmpl = max(tmpl, l);
      tmpr = min(tmpr, r);
    }
  }
  int ans = max(0, tmpr - tmpl + 1);

  cout << ans << endl;

  return 0;
}
