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
  int N;
  cin >> N;

  vector<int> W(N), S(N);
  REP(i, N) {
    cin >> W[i];
    if (i == 0) S[i] = W[i];
    else S[i] = S[i - 1] + W[i];
  }
  int m = S[N - 1];
  REP(i, N - 1){
    int tmp = S[N - 1] - S[i + 1];
    //cout << tmp << endl;
    m = min(m, abs(tmp - S[i + 1]));
  }

  cout << m << endl;



  return 0;
}
