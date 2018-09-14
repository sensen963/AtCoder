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

  ll D, G;
  cin >> D >> G;
  vector<ll> p(D), c(D);

  REP(i, D) {
    cin >> p[i] >> c[i];
  }

  ll ans = accumulate(p.begin(), p.end(), 0LL);

  ll tmp, amp, cmp;
  REP(i, pow(2, D)) {
    vector<int> use;
    for(int j = 0, tmp = i; j < D; j++) {
      use.push_back(tmp % 2);
      tmp /= 2;
    }
    //for (int i = 0; i < use.size(); i++) cout << use[i];
    //cout << endl;

    tmp = 0;
    amp = 0;
    REP(j, D) {
      tmp += use[j] * (p[j] * (j + 1) * 100 + c[j]);
      amp += use[j] * p[j];
    }
    //cout << tmp << " " << amp << endl;
    if (tmp == G) {
      ans = min(ans, amp);
    }else if (tmp < G) {
      ll l = D - 1;
      while(true) {
        if (use[l] == 0) break;
        l--;
      }
      //cout << l << endl;
      ll k = 0;
      while (k <= p[l]) {
        tmp += 100 * (l + 1);
        amp++;
        k++;
        //cout << tmp << endl;
        if (tmp >= G) {
          ans = min(ans, amp);
          break;
        }
      }
    } else {
      ans = min(ans, amp);
    }

  }
  cout << ans << endl;

  return 0;
}
