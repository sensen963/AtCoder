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

struct SS{
  string S;
  int score;
  int num;

  bool operator<(const SS& another) const {
  if (S != another.S)
    return S < another.S;
  if (score != another.score)
    return score > another.score; // 同様に比較演算子を反転
  return S < another.S;
  }
};

int main() {

  int N;
  cin >> N;
  vector<SS> V(N);
  REP(i, N)
  {
    cin >> V[i].S >> V[i].score;
    V[i].num = i + 1;
  }

  sort(V.begin(), V.end());

  REP(i, N) cout << V[i].num << endl;

  return 0;
}
