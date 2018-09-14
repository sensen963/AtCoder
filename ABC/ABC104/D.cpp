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

ll M = pow(10, 9) + 7;

// long long powm(long long a, long long b) {
//   if (b < 0) return 1;
//   long long res = 1;
//   for (ll i = 0; i < b; i++) {
//     if (res > M) res %= M;
//     res *= a;
//   }
//   return res;
// }

ll powm(ll x,ll k){
    if(k<0) return 0;
    ll res=1;
    while(k){
        if(k&1) res*=x;
        res%=M;
        x*=x;
        x%=M;
        k>>=1;
    }
    return res;
}
int main() {

  string s;

  cin >> s;

  ll n = s.size();

  vector<ll> left_a(n), left_q(n), right_c(n), right_q(n);
  // if (s[0] == 'A') {
  //   left_a[0] = 1;
  //   left_q[0] = 0;
  // } else if (s[0] == '?') {
  //   left_a[0] = 0;
  //   left_q[0] = 1;
  // }
  left_a[0] = 0;
  left_q[0] = 0;
  for (ll i = 0; i < n-1; i++) {
    if (s[i] == 'A') {
      left_a[i+1] = left_a[i] + 1;
      left_q[i+1] = left_q[i];
    } else if (s[i] == '?') {
      left_a[i+1] = left_a[i];
      left_q[i+1] = left_q[i] + 1;
    } else {
      left_a[i+1] = left_a[i];
      left_q[i+1] = left_q[i];
    }
  }

  // if (s[n-1] == 'C') {
  //   right_c[n-1] = 1;
  //   right_q[n-1] = 0;
  // } else if (s[n-1] == '?') {
  //   right_c[n-1] = 0;
  //   right_q[n-1] = 1;
  // }
  right_c[n-1] = 0;
  right_q[n-1] = 0;

  for (ll i = n-1; i >= 1; i--){
    if (s[i] == 'C') {
      right_c[i-1] = right_c[i] + 1;
      right_q[i-1] = right_q[i];
    }else if (s[i] == '?') {
      right_c[i-1] = right_c[i];
      right_q[i-1] = right_q[i] + 1;
    }else {
      right_c[i-1] = right_c[i];
      right_q[i-1] = right_q[i];
    }
  }

  // REP(i, n) cout << left_a[i];
  // cout << endl;
  // REP(i, n) cout << left_q[i];
  // cout << endl;
  // REP(i, n) cout << right_c[i];
  // cout << endl;
  // REP(i, n) cout << right_q[i];
  // cout << endl;


  ll ans = 0;

  ll right1, right, left1, left;
  ll tmp;
  for (ll i = 1; i < n-1; i++) {
    if (s[i] == 'B' || s[i] == '?') {

      tmp = (left_a[i] * powm(3, left_q[i]) % M + left_q[i] * powm(3, left_q[i] - 1) % M) % M * (right_c[i] * powm(3, right_q[i]) % M + right_q[i] * powm(3, right_q[i] - 1) % M) % M;
      //left = long(left_a[i] * pow(3, left_q[i]) + left_q[i] * long(pow(3, left_q[i] - 1))) % M;
      //right = long(right_c[i] * pow(3, right_q[i]) + right_q[i] * long(pow(3, right_q[i] - 1))) % M;
      // if (left_q[i] == 0) {
      //   left = left_a[i];
      // } else {
      //   left = left_a[i] * expmod(3, left_q[i], M) + left_q[i] * expmod(3, left_q[i] - 1, M);
      // }
      //
      // if (right_q[i] == 0) {
      //   right = right_c[i];
      // } else {
      //   right = right_c[i] * expmod(3, right_q[i], M) + right_q[i] * expmod(3, right_q[i] - 1, M);
      // }

      // left1 = expmod(3, left_q[i], M);
      // left = left_a[i] * left1 + left_q[i] * (left1 / 3);
      // right1 = expmod(3, right_q[i], M);
      // right = right_c[i] * right1 + right_q[i] * (right1 / 3);
      //tmp = left * right;
      tmp = tmp % M;
      ans += tmp;
      ans = ans % M;
      //ans = pow(3, left_q[i]);
      //cout << ans << endl;
    }
  }

  cout << ans << endl;

  return 0;
}
