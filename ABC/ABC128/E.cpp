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

#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)

struct even{
  ll start;
  int type;
  ll x;

  even(ll _start, int _type, ll _x){
    start = _start;
    type = _type;
    x = _x;
  }
};

int main() {

  ll N, Q;
  cin >> N >> Q;
  ll S, T, X;
  vector<even> SS;
  REP(i, N) {
    cin >> S >> T >> X;
    SS.push_back(even(S - X, 1, X));
    SS.push_back(even(T - X, -1, X));
  }
  vector<ll> D(Q);
  REP(i, Q) cin >> D[i];

  sort(SS.begin(), SS.end(), [](even& even1, even& even2){
    if (even1.start != even2.start) return (even1.start < even2.start);
    else return (even1.type < even2.type);
  });

  ll latest = 0;
  set<ll> stat;
  for (auto iter : D){
    while(latest < SS.size()){
      if (iter >= SS[latest].start){
        if (SS[latest].type == 1) stat.insert(SS[latest].x);
        else stat.erase(SS[latest].x);
        latest++;
      }
      else break;

    }
    if (stat.empty()) cout << -1 << endl;
    else cout << *stat.begin() << endl;
  }

  return 0;
}
