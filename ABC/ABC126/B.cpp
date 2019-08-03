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
  string s;
  cin >> s;

  int c = atoi(s.c_str());
  int a = c / 100;
  int b = c - 100 * a;

  //cout << a << " " << b << endl;
  string ans;
  if (1 <= a && a <= 12 && 1 <= b && b <= 12) ans = "AMBIGUOUS";
  else if (1 <= a && a <= 12) ans = "MMYY";
  else if (1 <= b && b <= 12) ans = "YYMM";
  else ans = "NA";


  cout << ans << endl;

  return 0;
}
