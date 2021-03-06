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

  int P, Q, R;
  int m, s;
  s = 0;
  m = 0;
  REP(i, 3){
    cin >> P;
    s += P;
    m = max(m, P);
  }

  cout << (s - m) << endl;
  return 0;
}
