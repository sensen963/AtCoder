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
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  int N, X;
  cin >> N >> X;
  vector<int> vec(N);
  REP(i, N) cin >> vec[i];

  int count = 0;
  REP(i, N) {
    count += vec[i];
    if (count > X) {
      cout << (i + 1) << endl;
      return 0;
    }
  }
  cout << (N + 1) << endl;
  return 0;
}
