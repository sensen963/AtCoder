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
  int N;
  cin >> N;

  vector<int> v(N);
  REP(i, N) cin >> v[i];

  sort(v.begin(), v.end());

  int ans = v[N / 2]  - v[N / 2 - 1] ;

  cout << ans << endl;
  return 0;
}
