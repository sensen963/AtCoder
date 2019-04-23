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

  int N;
  cin >> N;
  string ss;
  vector<int> vec(N);

  cin >> ss;
  int ww = 0;
  REP(i, N) {
    if (i == 0) {
      if (ss[i] == '.') vec[i] = 1;
      else vec[i] = 0;
    }else {
      if (ss[i] == '.') vec[i] = vec[i - 1] + 1;
      else vec[i] = vec[i - 1];
    }
    if (ss[i] == '.') ww++;
  }
  int min_tmp = ww;
  int tmp;
  REP(i, N){
    if (ss[i] == '.'){
      tmp = i - (vec[i] - 1) + (vec[N - 1] - vec[i]);
      min_tmp = min(min_tmp, tmp);
    }
  }


  //REP(i, N) cout << vec[i];

  cout << min_tmp << endl;
  return 0;
}
