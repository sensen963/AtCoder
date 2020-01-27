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

#define REP(i, n) for(long i = 0; i < (long)(n); i++)

ll minll(ll a, ll b) {
  if (a > b) return b;
  else return a;
}

int main() {

  ll n;
  cin >> n;

  vector<ll> array(n);
  ll tmp = 0;
  REP(i, n){
    cin >> array[i];
    tmp += array[i] - (i + 1);
    //tmp += array[i] - (i + 1);
  }

  //cout << tmp << endl;

  //tmp = round(double(tmp) / double(n));

  //cout << tmp << endl;
  ll tmp1;
  ll tmp2;

  tmp = tmp / n;
  tmp1 = tmp + 1;
  tmp2 = tmp - 1;
  //cout << tmp << endl;
  //cout << tmp1 << endl;
  ll sum0 = 0;
  ll sum1 = 0;
  ll sum2 = 0;
  REP(i, n) {
    sum0 += llabs(array[i] - (tmp2 + i + 1));
    sum1 += llabs(array[i] - (tmp + i + 1));
    sum2 += llabs(array[i] - (tmp1 + i + 1));
  }
  cout << minll(sum0, minll(sum1, sum2)) << endl;

  return 0;
}
