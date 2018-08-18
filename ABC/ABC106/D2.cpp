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

  ll N, M, Q;

  cin >> N >> M >> Q;

  ll ray[501][501] = {};

  ll a, b;
  for (int i = 0; i < M; i++){
    cin >> a >> b;
    for (int j = 1; j < a + 1; j++){
      for (int k = b; k < N + 1; k++){
        ray[j][k]++;
      }
    }
  }

  vector<ll> ans;
  for (int i = 0; i < Q; i++){
    cin >> a >> b;
    ans.push_back(ray[a][b]);
  }

  for (int i = 0; i < Q; i++){
    cout << ans[i] << endl;
  }


  return 0;
}
