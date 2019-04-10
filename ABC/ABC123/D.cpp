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
#include <functional>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X), B(Y), C(Z);
  REP(i, X) cin >> A[i];
  REP(i, Y) cin >> B[i];
  REP(i, Z) cin >> C[i];

  vector<ll> E;
  REP(i, X){
    REP(j, Y){
      E.push_back(A[i] + B[j]);
    }
  }

  sort(E.begin(), E.end(), greater<long long>());
  //REP(i, X*Y) cout << E[i] << " ";

  vector<ll> F;
  int kk = min(K, X * Y);
  REP(i, kk){
    REP(j, Z){
      F.push_back(E[i] + C[j]);
    }
  }
  sort(F.begin(), F.end(), greater<ll>());

  REP(i, K) cout << F[i] << endl;

  return 0;
}
