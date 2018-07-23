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

  int N;
  //
  cin >> N;
    vector<ll> vec(N);
  for(int i=0; i < N; i++) cin >> vec[i];
  //
  cout << accumulate(vec.begin(), vec.end(), 0) - N << endl;

  return 0;
}
