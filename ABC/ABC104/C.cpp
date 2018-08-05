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

int main() {

  int D, G;


  cin >> D >> G;
  vector<int> p(D+1), c(D+1);
  p[0] = 0;
  c[0] = 0;
  for (int i = 1; i <= D; i++){
    cin >> p[i] >> c[i];
  }

  vector<vector<int>> d(D);

  for (int i = 1; i <= D; i++){

    for (int j = 1; j <= p[i]; j++){
      if (i == 1){
        if (j == p[i]){
          d[i][j] = 100 * j + c[i]
        }else{
          d[i][j] = 100 * j
        }
      }
      if (j != p[i]){
        d[i][j] = max(100 * i * j, d[i-1][j])
      }
    }
  }

  return 0;
}
