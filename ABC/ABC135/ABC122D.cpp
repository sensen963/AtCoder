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

bool isok(int a, int b, int c, int d){
  bool ok = (a == 0 && b == 2 && d == 1) || (a == 0 && c == 2 && d == 1) || (b == 0 && c == 2 && d == 1) || (b == 0 && c == 1 && d == 2) ||
          (b == 2 && c == 0 && d == 1);
  ok = !ok;
  return ok;
}

const ll MOD = 1e9 + 7;

int main() {

  int N;
  cin >> N;

  //vector<vector<vector<vector<ll>>>> dp(N + 1, vector<ll>(4, vector<ll>(4, vector<ll>(4, 0))));
  ll dp[110][4][4][4] = {0LL};

  REP(i, N)REP(a, 4)REP(b, 4)REP(c, 4)REP(d, 4){
    if (i < 2) continue;
    if (i == 2) {
      if (!((a == 0 && b == 2 && c == 1) || (a == 0 && b == 1 && c == 2) || (a == 2 && b == 0 && c == 1))) dp[i][a][b][c] = 1;
    }
    else if (isok(a, b, c, d)) dp[i][b][c][d] = (dp[i - 1][a][b][c] + dp[i][b][c][d]) % MOD;
  }

  ll ans = 0;

  REP(a, 4)REP(b, 4)REP(c, 4) ans = (ans + dp[N - 1][a][b][c]) % MOD;

  cout << ans << endl;


  return 0;
}
