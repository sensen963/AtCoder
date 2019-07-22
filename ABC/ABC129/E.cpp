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

  string s;
  cin >> s;

  int N = s.length();

  const int MOD = 1e9 + 7;

  vector<ll> p3;
  vector<ll> p2;
  ll tmp2 = 1;
  ll tmp3 = 1;
  REP(i, N + 1){
    p2.push_back(tmp2);
    p3.push_back(tmp3);

    tmp2 = (tmp2 * 2) % MOD;
    tmp3 = (tmp3 * 3) % MOD;
  }

  ll ans = p3[N];

  ll cum = 0;
  REP(i, N){
    if (s[i] == '1') {
      cum++;
      continue;
    }
    ll tmp = p2[cum + 1];
    tmp = (tmp * p3[N - 1 - i]) % MOD;
    ans = (ans + MOD - tmp) % MOD;
  }

  cout << ans << endl;

  return 0;
}
