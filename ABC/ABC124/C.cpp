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

  string sss;
  cin >> sss;

  int len = sss.size();

  int d_e = 0;
  int d_o = 0;
  REP(i, len){
    if (i % 2 == 0){
      if (sss[i] == '0') d_e++;
      else d_o++;
    }else{
      if (sss[i] == '1') d_e++;
      else d_o++;
    }
  }

  cout << min(d_e, d_o) << endl;

  return 0;
}
