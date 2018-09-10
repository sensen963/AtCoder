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

  int w, h;
  cin >> h >> w;

  int array[h+3][w+3];

  REP(i, h) {
    REP (j, w) {
      cin >> array[i][j];
    }
  }

  vector<vector<int>> ans;
  REP(i, h) {
    REP (j, w) {
      if (array[i][j] % 2 == 1) {
        if (j < w - 1){
          array[i][j]--;
          array[i][j+1]++;
          //cout << i + 1 << " " << j + 1<< " " << i + 1 << " " << j + 2 << endl;
          ans.push_back({i+1, j+1, i+1, j+2});

        } else if (i != h - 1) {
          array[i][j]--;
          array[i+1][j]++;
          //cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << endl:
          ans.push_back({i+1, j+1, i+2, j+1});
        }
      }
    }
  }

  cout << ans.size() << endl;
  REP(i, ans.size()) {
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
  }
  return 0;
}
