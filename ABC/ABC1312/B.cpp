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

  int n;
  cin >> n;
  vector<int> p(n);
  REP(i, n) cin >> p[i];

  int ans = 0;
  REP(i, n - 2){
    if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) ans++;
    else if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) ans++;
  }

  cout << ans << endl;

  return 0;
}
