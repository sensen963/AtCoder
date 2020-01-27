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

  int n;
  cin >> n;

  ll min_l = INF;
  ll max_l = 0;
  ll tmp;
  REP(i, n){
    cin >> tmp;
    max_l = max(max_l, tmp);
    min_l = min(min_l, tmp);
  }

  cout << max_l - min_l << endl;



  return 0;
}
