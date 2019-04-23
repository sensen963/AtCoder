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
//#include <function>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(long i = 0; i < (long)(n); i++)


int main() {

  long N;
  cin >> N;
  vector<long> array(N);
  long sum_a = 0;
  long max_a = 0;
  long ans = 1;
  const long MOD = 998244353;
  REP(i, N) {
    cin >> array[i];
    sum_a += array[i];
    max_a = max_a > array[i]? max_a : array[i];
    ans = (ans * 3) % MOD;
  }

  //long dp[300][(300 * 300) + 1] = {0};
  //long dp1[300][(300 * 300) + 1] = {0};

  vector<vector<long>> dp(300, vector<long>(300 * 310 + 1L, 0L));
  vector<vector<long>> dp1(300, vector<long>(300 * 310 + 1L, 0L));

  dp[0][array[0]] = 1;
  dp[0][0] = 2;
  dp1[0][array[0]] = 1;
  dp1[0][0] = 1;

  REP(i, N - 1){
    REP(j, (N * max_a) + 1) {
      dp[i + 1][j] = (dp[i + 1][j] + 2 * dp[i][j]) % MOD;
      dp[i + 1][j + array[i + 1]] = (dp[i + 1][j + array[i + 1]] + dp[i][j]) % MOD;
      dp1[i + 1][j] = (dp1[i + 1][j] + dp1[i][j]) % MOD;
      dp1[i + 1][j + array[i + 1]] = (dp1[i + 1][j + array[i + 1]] + dp1[i][j]) % MOD;
    }
  }

  long tmp1 = 0;
  long tmp2 = 0;
  if (sum_a % 2 == 0){
    for(long i = sum_a / 2; i < N * max_a + 1; i++){
      tmp1 = (tmp1 + dp[N - 1][i]) % MOD;
      //tmp2 = (tmp2 + dp1[N - 1][i]) % MOD;
    }
    tmp2 = dp1[N - 1][sum_a / 2] % MOD;
  }else{
    for(long i = (sum_a + 1) / 2; i < N * max_a + 1; i++){
      tmp1 = (tmp1 + dp[N - 1][i]) % MOD;
    }
  }
  //cout << ans << endl;
  //cout << tmp1 << endl;
  //cout << tmp2 << endl;


  tmp1 = (tmp1 * 3) % MOD;
  tmp2 = (tmp2 * 3) % MOD;
  ans = (ans - tmp1) % MOD;
  if (ans < 0) ans += MOD;
  ans = (ans + tmp2) % MOD;

  cout << ans << endl;

  return 0;
}
