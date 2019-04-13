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


  int N, Q;

  cin >> N >> Q;
  string ss;
  cin >> ss;
  vector<int> l(Q), r(Q);
  REP(i, Q) cin >> l[i] >> r[i];
  vector<int> acc(N);

  acc[0] = 0;
  for(int i = 1; i < N; i++){
    if (ss[i] == 'C' && ss[i-1] == 'A'){
      acc[i] = acc[i-1] + 1;
    } else acc[i] = acc[i-1];
  }

  REP(i, Q){
    if (l[i] == 0 || l[i] == 1){
      cout << acc[r[i]-1] << endl;
    }else cout << acc[r[i]-1] - acc[l[i]-1] << endl;
  }
  //for(auto oo : acc) cout << oo << ",";

  return 0;
}
