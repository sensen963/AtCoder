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
  cin >> ss;

  bool flag = true;
  int tmp = 0;

  REP(i, N){
    if (flag) {
      if (ss[i] == '#'){
        flag = false;
      }
    }else{
      if (ss[i] == '.') tmp++;
    }

  }

  flag = true;
  int tmp1 = 0;
  REP(i, N){
    if (flag){
      if (ss[N - 1 - i] == '.') flag = false;
    }
    else {
      if (ss[N - 1 - i] == '#') tmp1++;
    }
  }

  cout << min(tmp, tmp1) << endl;
  return 0;
}
