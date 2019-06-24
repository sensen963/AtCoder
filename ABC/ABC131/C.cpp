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
template<typename TypeInt>
TypeInt G_C_D(TypeInt a, TypeInt b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        a %= b;
        if (a == 0) return b;
        b %= a;
    }
    return a;
}


template<typename TypeInt>
TypeInt L_C_M(TypeInt a, TypeInt b) {
    if( a == 0 && b == 0)return 0;
    return a / G_C_D(a, b) * b;
}

int main() {
  ll A, B, C, D;

  cin >> A >> B >> C >> D;

  ll lcm = L_C_M(C, D);

  ll ans = B / lcm - A/ lcm;
  if (A % lcm == 0) ans++;


  ll ans1 = B / C - A / C;
  ll ans2 = B / D - A / D;
  if (A % C == 0) ans1++;
  if (A % D == 0) ans2++;

  //cout << ans << ", " << ans1 << ", " << ans2 << endl;
  cout << (B - A + 1 + ans - ans1 - ans2) << endl;

  return 0;
}
