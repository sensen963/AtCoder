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
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

P bino(vector<ll> array, ll s, ll e){

  ll a = s;
  ll b = e;
  if (e - s == 1) return P(s, e);
  while(b - a > 1){
    ll i = (a + b) / 2;
    ll tmp = array[e] - 2 * array[i];
    if (tmp >= 0){
      a = i;
    }else{
      b = i;
    }
  }
  if (abs(array[e] - 2 * array[a]) < abs(array[e] - 2 * array[b])){
    return P(array[a], array[e] - array[a]);
  }else{
    return P(array[b], array[e] - array[b]);
  }
}

int main() {

  ll n;
  cin >> n;
  vector<ll> array(n), summ(n);
  REP(i, n) {
    cin >> array[i];
    if (i != 0) summ[i] = summ[i-1] + array[i];
    else summ[i] = array[i];
  }

  ll j = 0;
  ll l = 2;
  ll ans = 1e9 + 5;
  vector<ll> tmp(4);
  for(ll i = 1; i < n - 1; i++) {

    P p = bino(summ, 0, i);
    P q = bino(summ, i+1, n-1);
    tmp[0] = p.first;
    tmp[1] = p.second;
    tmp[2] = q.first;
    tmp[3] = q.second;
    sort(tmp.begin(), tmp.end());
    ans = min(ans, tmp[3] - tmp[1]);

  }
  cout << ans << endl;


  return 0;
}
