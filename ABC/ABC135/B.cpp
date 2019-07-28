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
  int N;
  cin >> N;
  int a;
  int tmp = 0;
  REP(i, N){
    cin >> a;
    if (a != i + 1) tmp++;
  }
  auto ans = "NO";
  if (tmp == 0 || tmp == 2) ans = "YES";

  cout << ans << endl;


  return 0;
}
