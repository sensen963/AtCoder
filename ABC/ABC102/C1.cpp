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

  ll n;
  cin >> n;

  vector<ll> array(n);
  REP(i, n){
    cin >> array[i];
    array[i] = array[i] - (i + 1);
    //tmp += array[i] - (i + 1);
  }
  sort(array.begin(), array.end());

  ll tmp;
  if (n % 2 == 0) {
    tmp = (array[n / 2] + array[n / 2 - 1]) / 2;
  } else {
    tmp = array[n / 2];
  }

  ll ans = 0;
  REP(i, n) ans += llabs(array[i] - tmp);

  cout << ans << endl;

  return 0;
}
