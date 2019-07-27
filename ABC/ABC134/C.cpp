
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

  ll N;
  cin >> N;
  ll m1 = 0;
  ll m2 = 0;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
    if (A[i] >= m1){
      m2 = m1;
      m1 = A[i];
    }else if(A[i] > m2) m2 = A[i];
  }
  REP(i, N){
    if (A[i] == m1) cout << m2 << endl;
    else cout << m1 << endl;
  }

  return 0;
}
