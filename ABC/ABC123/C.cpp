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
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define min_ll(a, b) a<b? a :b

int main() {

  ll N;
  ll t = 0;
  vector<ll> a(5);
  cin >> N;
  REP(i, 5) cin >> a[i];
  vector<ll> a_tmp = {N, 0LL, 0LL, 0LL, 0LL, 0LL};
  //vector<ll> a_tmp1 = a_tmp;
  vector<ll> trans(5);
/*
  while (a_tmp[5] != N){
    t++;
    REP(i, 5) {
      if (a_tmp[i] - a[i] > 0) trans[i] = a[i];
      else trans[i] = a_tmp[i];
    }
    REP(i, 6) {
      if (i == 0) a_tmp[i] -= trans[i];
      else if (i == 5) a_tmp[i] += trans[i-1];
      else a_tmp[i] += trans[i-1] - trans[i];
    }
    //cout << t << ":";
    //REP(i, 6) cout << a_tmp[i];
    //cout << endl;
  }
*/
  ll min_t = *min_element(a.begin(), a.end());
  ll ans;
  if (N % min_t == 0){
    ans = N / min_t + 4;
  } else {
    ans = N / min_t + 4 + 1;
  }
  cout << ans << endl;

  return 0;
}
