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

  ll ray[502][502] = {};

  // vector<vector<ll>> ray;
  //
  // ray.resize(500+1);
  // for (int i = 0; i < N + 1; i++) ray[i].resize(500+1);

  ll a, b;
  for (ll i = 0; i < M; i++){
    cin >> a >> b;
    ray[a][b]++;
  }

  for (int i = 1; i < N + 1; i++){
    for (int j = 1; j < N + 1; j++){
      ray[i][j+1] += ray[i][j];
    }
  }

  for (int i = N; i >= 1; i--){
    for (int j = 1; j < N + 1; j++){
      ray[i-1][j] += ray[i][j];
    }
  }

  vector<ll> ans;
  for (ll i = 0; i < Q; i++){
    cin >> a >> b;
    ans.push_back(ray[a][b]);
  }

  // for (int i = 1; i < N + 1; i++){
  //   for (int j = 1; j < N + 1; j++){
  //     cout <<ray[i][j];
  //   }
  //   cout << endl;
  // }


  for (ll i = 0; i < Q; i++){
    cout << ans[i] << endl;
  }


  return 0;
}
