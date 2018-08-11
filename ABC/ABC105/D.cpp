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

  ll N, M;

  cin >> N >> M;

  vector<ll> A(N);

  for (int i = 0; i < N; i++) cin >> A[i];

  // for (int i = 0; i < N; i++){
  //   for (int j = i; j < N; j++){
  //     if (accumulate(A.begin()+i, A.begin()+j+1, 0LL) % M == 0){
  //       cout << i << "," << j << endl;
  //     }
  //   }
  // }

  vector<ll> left_v(N+1);
  map<ll, ll> m{};
  left_v[0] = 0;
  for (int i = 0; i < N; i++){
    left_v[i+1] = (left_v[i] + A[i]) % M;
  }

  for (int x : left_v){
    m[x]++;
  }

  ll count = 0;
  for (auto iter = m.begin(); iter != m.end(); iter++){
    //cout << iter->first << ":" << iter->second << endl;
    if (iter->second != 1) {
      count += iter->second * (iter->second - 1) / 2;
    }
  }


  cout << count << endl;



  return 0;
}
