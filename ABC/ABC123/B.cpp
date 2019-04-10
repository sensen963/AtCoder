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

  vector<int> a(5);
  int min_a = 10;
  int tmp = 0;
  REP(i, 5){
    cin >> a[i];
    if (a[i] % 10 != 0) {
      min_a = min(min_a, a[i] % 10);
      tmp += 10 + a[i] - (a[i] % 10);
    } else {
      tmp += a[i];
    }
  }
  tmp -= 10 - min_a;
  cout << tmp << endl;
  return 0;
}
