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
  int N, K;

  cin >> N >> K;

  //cout << (N%K) << endl;
  if (N % K == 0){
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }

  return 0;
}
