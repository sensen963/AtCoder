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

  string s, t;

  cin >> s >> t;

  int n = s.size();

  vector<vector<char>> arrays(26);

  REP(i, n) arrays[s[i] - 'a'].push_back(t[i]);
  //REP(i, arrays.size()) cout << arrays[i] << endl;

  bool tmp = true;
  REP(i, 26) {
    for (int j = 0; j < arrays[i].size(); j++) {
      if(arrays[i][0] != arrays[i][j]) {
        tmp = false;
        break;
      }
    }
  }

  vector<vector<char>> arrayt(26);

  REP(i, n) arrayt[t[i] - 'a'].push_back(s[i]);
  //REP(i, arrays.size()) cout << arrays[i] << endl;
  REP(i, 26) {
    for (int j = 0; j < arrayt[i].size(); j++) {
      if(arrayt[i][0] != arrayt[i][j]) {
        tmp = false;
        break;
      }
    }
  }


  if (tmp) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }

  return 0;
}
