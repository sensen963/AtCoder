

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
  int n;
  cin >> n;

  vector<ll> x(n), y(n);
  int m = 31;
  REP(i, n) cin >> x[i] >> y[i];
  REP(i, n-1) {
    if ((x[i] + y[i] + long(pow(2, 31))) % 2 != (x[i+1] + y[i+1] + long(pow(2, 31))) % 2) {
      cout << -1 << endl;
      return  0;
    }
  }
  int odd = 0;
  if ((x[0] + y[0]) % 2 == 0) odd = 1;
  vector<ll> u(n), v(n);
  REP(i, n) {
    u[i] = x[i] + y[i] + odd;
    v[i] = x[i] - y[i] + odd;
  }
  cout << m + odd << endl;
  REP(i, m) cout << long(pow(2, i)) << " ";
  if (odd == 1) cout << 1;
  cout << endl;

  ll tmp_u, tmp_v;
  REP(i, n){
    vector<ll> arrayu(31, 0), arrayv(31, 0);
    tmp_u = (u[i] + pow(2, 31) - 1) / 2;
    tmp_v = (v[i] + pow(2, 31) - 1) / 2;
    REP(j, 31) {
      arrayu[j] = tmp_u % 2;
      arrayv[j] = tmp_v % 2;
      tmp_u /= 2;
      tmp_v /= 2;
      if (arrayu[j] == 0 && arrayv[j] == 0) {
        cout << "L";
      } else if (arrayu[j] == 0 && arrayv[j] == 1) {
        cout << "D";
      } else if (arrayu[j] == 1 && arrayv[j] == 0) {
        cout << "U";
      } else if (arrayu[j] == 1 && arrayv[j] == 1) {
        cout << "R";
      }
    }
    if(odd == 1) cout << "L";
    cout << endl;
  }




  return 0;
}
