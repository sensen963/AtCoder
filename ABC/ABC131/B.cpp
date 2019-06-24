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

  int N, L;

  cin >> N >> L;

  int ans = 0;
  int tmp = abs(L);
  REP(i, N){
    ans += L + i;
    if (tmp > abs(L + i)) tmp = abs(L + i);
  }
//cout << ans << endl;
  if (L >= 0) ans -= tmp;
  else if (L + N - 1 <= 0) ans += tmp;

  cout << ans << endl;

  return 0;
}
