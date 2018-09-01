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
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  ll N, K;

  cin >> N >> K;

  ll mm = N / K;

  ll ans = mm * mm * mm;

  if (K % 2 == 0) {
    if (N % K * 2 >= K) {
      ans += (mm + 1) * (mm + 1) * (mm + 1);
    } else {
      ans *= 2;
    }
  }

  cout << ans << endl;
  return 0;
}
