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

const ll MOD = 1e9 + 7;


int main() {

  string S;
  cin >> S;

  int N = S.size();
  vector<vector<ll>> dp(N + 1, vector<ll>(13, 0));
  dp[0][0] = 1;

  REP(i, N){
    if (S[i] == '?')REP(j, 13)REP(tmp, 10){
      dp[i + 1][(j * 10 + tmp) % 13] += dp[i][j];
    }else{
      int tmp = S[i] - '0';
      REP(j, 13){
        dp[i + 1][(j * 10 + tmp) % 13] += dp[i][j];
      }
    }
    REP(j, 13) dp[i + 1][j] %= MOD;
  }

  cout << dp[N][5] << endl;



  return 0;
}
