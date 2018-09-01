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


  int K;
  int out;
  cin >> K;
  if (K % 2 == 0) {
    out = (K / 2) * (K / 2);
  } else {
    out = (K * K - 1) / 4;
  }
  cout << out << endl;

  return 0;
}
