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

  ll N, K;
  cin >> N >> K;
  vector<ll> vec(N);
  REP(i, N) {
    cin >> vec[i];
  }

  ll tmp = vec[0];
  ll count = 0;
  int end = 0;
  for (int start = 0; start < N; start++){
    while(tmp < K){
      if (end == N - 1) break;
      end++;
      tmp += vec[end];
    }
    if (tmp >= K){
      count += N - end;
    }

    tmp -= vec[start];
  }

  cout << count << endl;



  return 0;
}
