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

vector<long long> divdiv (long long a){
vector<long long> p(2);

  if (a % -2 == -1){
    p[0] = a / -2 + 1;
    p[1] = 1;
  }else {
    p[0] = a / -2;
    p[1] = a % -2;
  }

  return p;
}

int main() {

  long long N;

  cin >> N;

  if (N == 0){
    cout << 0 << endl;
    return 0;
  }

  vector<int> ans;

  while (N != 1) {
    vector<long long> p = divdiv(N);

    ans.push_back(p[1]);
    N = p[0];
  }
  ans.push_back(1);
  for (int i = ans.size() - 1; i  >= 0; i--){
    cout << ans[i];
  }
  cout << endl;

  //cout << (N % -2) << endl;
  //cout << (N / -2) << endl;

  return 0;
}
