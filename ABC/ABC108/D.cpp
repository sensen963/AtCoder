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

  ll L;
  cin >> L;

  int r = 0;
  while (pow(2, r) <= L) r++;
  r--;

  vector<int> vr, vl, w;
  for (int i = r; i >= 0; i--) {
    if (L - pow(2, r) - pow(2, i - 1) >= 0) {
      vr.push_back(i);
      vl.push_back(r + 1);
      w.push_back(L - pow(2, i - 1));
      L -= pow(2, i - 1);
    }
  }

  // for (int i = 0; i != vr.size(); i++) {
  //   cout << vr[i] << vl[i] << w[i] << endl;
  // }
  for (int i = 1; i <= r; i++){
    vr.push_back(i);
    vr.push_back(i);
    vl.push_back(i + 1);
    vl.push_back(i + 1);
    w.push_back(pow(2, i - 1));
    w.push_back(0);
  }

  cout << (r + 1) << " " << vr.size() << endl;
  for (int i = 0; i != vr.size(); i++){
    cout << vr[i] << " " << vl[i] << " " << w[i] << endl;
  }



  return 0;
}
