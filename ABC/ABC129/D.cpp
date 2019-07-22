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
  int H, W;
  cin >> H >> W;
  vector<vector<char>> m(H + 1, vector<char>(W + 1, '#'));
  REP(i, H) {
    REP(j, W) {
      cin >> m[i][j];
    }
  }

  vector<vector<int>> Wid(H, vector<int>(W));
  vector<vector<int>> Hei(H, vector<int>(W));

  int tmp = 0;
  int start;
  REP(i, H) REP(j, W){
    if (m[i][j] == '#') {
      Wid[i][j] = -1;
      continue;
    }
    start = j;
    while(m[i][j] != '#') j++;
    for(int cnt = start; cnt < j; cnt++) Wid[i][cnt] = j - start;
  }
  REP(j, W) REP(i, H){
    if (m[i][j] == '#') {
      Hei[i][j] = -1;
      continue;
    }
    start = i;
    while(m[i][j] != '#') i++;
    for(int cnt = start; cnt < i; cnt++) Hei[cnt][j] = i - start;
  }

  int mmax = 0;
  REP(i, H) REP(j, W){
    if (m[i][j] != '#'){
      mmax = max(mmax, Wid[i][j] + Hei[i][j]);
    }
  }

  // REP(i, H) {
  //   REP(j, W) cout << Wid[i][j];
  //   cout << endl;
  // }
  cout << (mmax - 1) << endl;

  return 0;
}
