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

  ll L ,R;
  cin >> L >> R;

  ll tmp = (R - L) % 2019;
  ll ans = 2018;
  if ((R - L + 1) > 2019) ans = 0;
  else{
    for(ll i = L; i < R; i++) for(ll j = L + 1; j <= R; j++){
      ll left = i % 2019;
      ll right = j % 2019;
      ll hoge = (left * right) % 2019;
      //cout << left << right<< endl;
      ans = hoge < ans ? hoge : ans;
      if (ans == 0) break;
    }
  }

  cout << ans << endl;
  return 0;
}
