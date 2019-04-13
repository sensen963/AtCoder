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


int main() {


  int N, M, C;
  cin >> N >> M >> C;

  vector<int> B(M);
  int A[N][M];
  REP(i, M) cin >> B[i];
  REP(i, N) REP(j, M) cin >> A[i][j];

  int ans = 0;
  int tmp;
  REP(i, N){
    tmp = C;
    REP(j, M){
      tmp += A[i][j] * B[j];
    }
    if (tmp > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
