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

  vector<int> x1(2), x2(2), x3(2), x4(2);
  cin >> x1[0] >> x1[1] >> x2[0] >> x2[1];

  x3[0] = x2[0] - (x2[1] - x1[1]);
  x3[1] = x2[1] + (x2[0] - x1[0]);
  x4[0] = x3[0] - (x2[0] - x1[0]);
  x4[1] = x3[1] - (x2[1] - x1[1]);

  cout << x3[0] << " " << x3[1] << " " << x4[0] << " " << x4[1] << endl;

  return 0;
}
