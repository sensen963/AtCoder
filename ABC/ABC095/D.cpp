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
#include <typeinfo>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

ll sum_vect(vector<ll> vect, int N){
  ll sum_ans = 0;
  for(int i = 0; i < N+1; i++){
    sum_ans += vect[i];
  }

  return sum_ans;
}

ll sum_vect1(vector<ll> vect, int j, int N){
  ll sum_ans = 0;
  for(int i = j; i < N; i++){
    sum_ans += vect[i];
  }

  return sum_ans;
}
int main() {

  ll N, C;

  cin >> N >> C;

  vector<ll> x(N);
  vector<ll> v(N);
  for(int i=0; i < N; i++){
    // cin >> x[i] >> v[i];
    scanf("%lld", &x[i]);
    scanf("%lld", &v[i]);
  }
  ll max_sum = 0;

  vector<ll> x1(N), v1(N);
  // x1 = x;
  // v1 = v;
  // reverse(x1.begin(), x1.end());
  // reverse(v1.begin(), v1.end());
  for(int i = 0; i < N; i++){
    x1[i] = C - x[N - 1 - i];
    v1[i] = v[N - 1 - i];
  }

  // for (int i = 0; i < N; i++){
  //   x1[i] = C - x1[i];
  // }
  // x.push_back(0);
  // x1.push_back(0);
  // v.push_back(0);
  // v1.push_back(0);
  // for(int i=0; i < N; i ++) cout << x1[i];
  // cout << endl;

  // to left

  vector<ll> f(N), g(N);
  vector<ll> f1(N), g1(N);

  ll sum_vector = 0;
  ll sum_vector1 = 0;

  for(int i=0; i < N; i++){
    // f[i] = accumulate(v.begin(), v.begin()+i+1, 0) - x[i];
    // f1[i] = accumulate(v1.begin(), v1.begin()+i+1, 0) - x1[i];
    sum_vector += v[i];
    sum_vector1 += v1[i];
    f[i] = sum_vector - x[i];
    f1[i] = sum_vector1 - x1[i];
    //cout << f[i] << endl;
  }

  g[0] = f[0];
  g1[0] = f1[0];
  for(int i=1; i < N; i++){
    // g[i] = *max_element(f.begin(), f.begin()+i+1);
    // g1[i] = *max_element(f1.begin(), f1.begin()+i+1);
    g[i] = max(g[i-1], f[i]);
    g1[i] = max(g1[i-1], f1[i]);
  }
  ll tmp = 0;
  ll tmp1 = 0;

  sum_vector = 0;
  sum_vector1 = 0;
  for(int i=N-1; i >= 0; i--){
    if (i == 0){
      // tmp = accumulate(v.begin()+i, v.end(), 0) - 2 * (C - x[i]);
      // tmp1 = accumulate(v1.begin()+i, v1.end(), 0) - 2 * (C - x1[i]);
      // tmp = sum_vect1(v, i, N) - 2 * (C - x[i]);
      // tmp1 = sum_vect1(v1, i, N) - 2 * (C - x1[i]);
      sum_vector += v[i];
      sum_vector1 += v1[i];
      tmp = sum_vector - 2 * (C - x[i]);
      tmp1 = sum_vector1 - 2 * (C - x1[i]);
    } else{
      sum_vector += v[i];
      sum_vector1 += v1[i];
      tmp = sum_vector - 2 * (C - x[i]) + g[i-1];
      tmp1 = sum_vector1 - 2 * (C - x1[i]) + g1[i-1];
  }
  // cout << "tmp:" << tmp << endl;
  // cout << "tmp1:" << tmp1 << endl;
    max_sum = max(max_sum, tmp);
    max_sum = max(max_sum, tmp1);
  }

  max_sum = max(max_sum, g[N-1]);
  max_sum = max(max_sum, g1[N-1]);

  cout << max_sum << endl;

  // for (int i = 0; i < N; i++) cout << x[i];
  // cout << endl;
  // for (int i = 0; i < N; i++) cout << v[i];
  // cout << endl;
  // //
  // for (int i = 0; i < N; i++) cout << f[i] << " ";
  // cout << endl;
  // for (int i = 0; i < N; i++) cout << g[i] << " ";
  // cout << endl;
  // for (int i = 0; i < N; i++) cout << *(v1.begin()+i) << " ";






  //cout << *x.begin() << endl << *(x.end()-1) << endl;
  //cout << typeid(int(3)).name() << endl;
  return 0;
}
