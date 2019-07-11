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

const ll MOD = pow(10, 9) + 7;

ll Perm(ll n, ll r){
  if (n < r) return 0;
  ll tmp = 1;
  ll n1 = n;
  REP(i, r){
    tmp *= n1;
    tmp %= MOD;
    n1--;
  }
  return tmp;
}


ll dfs(vector<vector<ll>>& tree, ll target, ll parent, ll K){

  ll cs = tree[target].size() - 1;
  ll ans;
  if (target == 1) {
    cs++;
    ans = Perm(K - 1, cs);
  }
  else ans = Perm(K - 2, cs);
  //cout << ans << endl;

  for(auto child : tree[target]){
    if (child == parent) continue;
    ans *= dfs(tree, child, target, K);
    ans %= MOD;
  }
  return ans;

}

int main() {

  ll N, K;
  cin >> N >> K;

  ll tmp, tmp1, a, b;
  vector<vector<ll>> tree(N);
  REP(i, N - 1){
    cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  ll ans = K * dfs(tree, 0, -1, K);
  ans %= MOD;

  cout << ans << endl;

  //REP(i, N) for(auto j : tree[i]) cout << j;
  return 0;
}
