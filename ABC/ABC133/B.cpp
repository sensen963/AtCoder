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

int dist(vector<int> x, vector<int> y, int D){
  int tmp = 0;
  REP(i, D) tmp += (x[i] - y[i]) * (x[i] - y[i]);
  return tmp;
}

int main() {

  int N, D;
  cin >> N >> D;

  vector<vector<int>> x(N, vector<int>(D));
  REP(i, N)REP(j, D) cin >> x[i][j];

  int count = 0;
  REP(i, N)REP(j, N){
    if (i == j) continue;
    int tmp = dist(x[i], x[j], D);
    int sq = (int)sqrt(tmp);
    //cout << tmp << " " << sq << endl;
    if (tmp == sq * sq) count++;

  }

  cout << (count / 2) << endl;

  return 0;
}
