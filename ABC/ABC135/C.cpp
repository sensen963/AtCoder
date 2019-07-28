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

  vector<ll> A(N + 1), B(N + 1);
  REP(i, N + 1) cin >> A[i];
  REP(i, N) cin >> B[i];

  ll tmp = 0;
  ll ans = 0;
  REP(i, N){
    if (A[i] > tmp + B[i]) {
      ans += tmp + B[i];
      tmp = 0;
    }
    else{
      ans += A[i];
      tmp = B[i] - max(A[i] - tmp, 0LL);
    }
  }
  if (A[N] >= tmp) ans += tmp;
  else ans += A[N];

  cout << ans << endl;

  return 0;
}
