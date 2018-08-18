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

  //ll ray[501][501] = {};
  vector<vector<ll>> ray(N+1);

  ll a, b;
  for (int i = 0; i < M; i++){
    cin >> a >> b;
    ray[a].push_back(b);
  }

  vector<ll> ans;
  ll tmp;
  for (int i = 0; i < Q; i++){
    tmp = 0;
    cin >> a >> b;
    for (int j = a; j < b + 1; j++){
      for (auto iter = ray[j].begin(); iter != ray[j].end(); iter++){
        if (*iter <= b) tmp++;
      }
    }
    ans.push_back(tmp);
  }

  for (int i = 0; i < Q; i++){
    cout << ans[i] << endl;
  }


  return 0;
}
