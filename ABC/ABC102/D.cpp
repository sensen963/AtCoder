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
#include <fstream>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)

vector<ll> array2;

P bino(ll s, ll e){
  ll a = s;
  ll b = e;
  ll base = s == 0 ? 0 : array2[s-1];
  if (e - s == 1) {
    return P(array2[s] - base, array2[e] - array2[s]);
  }
  while(b - a > 1){
    ll i = (a + b) / 2;
    ll tmp = array2[e] - 2 * array2[i] + base;
    if (tmp >= 0){
      a = i;
    }else{
      b = i;
    }
  }

  if (abs(array2[e] - 2 * array2[a] + base) < abs(array2[e] - 2 * array2[b] + base)){
    return P(array2[a] - base, array2[e] - array2[a]);
  }else{
    return P(array2[b] - base, array2[e] - array2[b]);
  }
}

int main() {
  //std::ifstream in("input.txt");
  //std::cin.rdbuf(in.rdbuf());

  ll n;
  cin >> n;
  vector<ll> array1(n);
  array2.resize(n);
  REP(i, n) {
    cin >> array1[i];
    if (i != 0) array2[i] = array2[i-1] + array1[i];
    else array2[i] = array1[i];
  }

  ll j = 0;
  ll l = 2;
  ll ans = 1e9 + 5;
  vector<ll> tmp(4);
  for(ll i = 1; i < n - 2; i++) {

    P p = bino(0, i);
    P q = bino(i+1, n-1);
    //if (i > 1e4)cout << i << endl;
    /*
    tmp[0] = p.first;
    tmp[1] = p.second;
    tmp[2] = q.first;
    tmp[3] = q.second;
    */
    ll big = max(max(p.first, p.second), max(q.first, q.second));
    ll small = min(min(p.first, p.second), min(q.first, q.second));
    //sort(tmp.begin(), tmp.end());
    ans = min(ans, big - small);

  }
  cout << ans << endl;


  return 0;
}
