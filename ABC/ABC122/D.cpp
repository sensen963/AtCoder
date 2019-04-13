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

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


bool isok(int a, int b, int c, int d){
  bool ans = true;
  if ((b == 0 && c == 2 && d == 1) || (b == 0 && c == 1 && d == 2) || (b == 2 && c == 0 && d == 1) || (a == 0 && b == 2 && d == 1) || (a == 0 && c == 2 && d == 1)){
    ans = false;
  }
  return ans;
}

int main() {

  ll MOD = 1e9 + 7;
  int N;
  cin >> N;

  ll dp[110][4][4][4] = {0LL};

  dp[0][3][3][3] = 1;
  for(int i = 0; i < N; i++){
    REP(j, 4){
      REP(k, 4){
        REP(l, 4){

          REP(m, 4){
            if (isok(j, k, l, m)){
              dp[i+1][k][l][m] = (dp[i+1][k][l][m] + dp[i][j][k][l]) % MOD;
            }
          }
        }
      }
    }
  }
  ll ans = 0LL;
  REP(i, 4) REP(j, 4) REP(k, 4){
     ans += dp[N][i][j][k];
     ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
