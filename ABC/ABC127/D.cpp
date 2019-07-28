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

struct card{
  ll count;
  ll value;

  card(ll a, ll b){
    count = a;
    value = b;
  }
};

int main() {
  ll n, m;
  cin >> n >> m;

  ll tmp, tmp1;
  vector<card> v;
  REP(i, n){
    cin >> tmp;
    v.push_back(card(1, tmp));
  }
  REP(i, m){
    cin >> tmp >> tmp1;
    v.push_back(card(tmp, tmp1));
  }
  sort(v.begin(), v.end(), [](card a, card b){
    return a.value > b.value;
  });

  ll ans = 0;
  for(auto iter : v){
    if (iter.count >= n){
      ans += iter.value * n;
      break;
    }
    n -= iter.count;
    ans += iter.value * iter.count;
  }

  cout << ans << endl;

  return 0;
}
