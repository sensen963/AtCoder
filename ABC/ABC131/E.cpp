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

  int K, N;
  cin >> N >> K;

  int count = (N - 1) * (N - 2) / 2 - K;
  if (count < 0) {
    cout << -1 << endl;
    return 0;
  }

  count += N - 1;
  cout << count << endl;

  int c = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      cout << i << " " << j << endl;
      c++;
      if (c == count) break;
    }
    if (c == count) break;
  }


  return 0;
}
