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

int auau(int r, int D, int x){
  return (r * x - D);
}

int main() {

  int r, D, x;
  cin >> r >> D >> x;

  int tmp = x;
  REP(i, 10){
    tmp = auau(r, D, tmp);
    cout << tmp << endl;
  }
  return 0;
}
