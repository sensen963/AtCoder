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

  const int MOD = 1e9 + 7;
  int N, M;
  cin >> N >> M;

  vector<int> a(M);
  REP(i, M) cin >> a[i];
  if (M == 0) a.push_back(N + 2);

  vector<int> dp(N + 1, 0);

  auto iter = a.begin();
  REP(i, N + 1){
    if (*iter == i) {
      iter++;
      continue;
    }
    if (i == 0) dp[i] = 1;
    else if (i == 1) dp[i] = dp[i - 1];
    else dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  }

  cout << dp[N] << endl;
  return 0;
}
