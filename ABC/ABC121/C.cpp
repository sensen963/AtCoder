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
//#include <function>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  int N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> A(N);
  REP(i, N) cin >> A[i].first >> A[i].second;

  sort(A.begin(), A.end(), [](pair<ll, ll> x, pair<ll, ll> y) { return x.first < y.first;});

  int res = M;
  ll price = 0LL;
  ll tmp;
  REP(i, N){
    if (res > A[i].second){
      res -= A[i].second;
      price += A[i].first * A[i].second;
    }else {
      price += res * A[i].first;
      break;
    }
  }
  //REP(i, N) cout << A[i].first << ":" <<A[i].second << endl;
  cout << price << endl;
  return 0;
}
