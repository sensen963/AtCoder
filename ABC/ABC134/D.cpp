
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

  vector<int> A(N + 1), B(N + 1, 0), C;
  REP(i, N) cin >> A[i + 1];

  for(int i = N; i >= 1; i--){
    int tmp = 0;
    for(int j = 1; j <= N && i * j <= N; j++){
      tmp += B[i * j];
    }
    if (tmp % 2 != A[i]) {
      C.push_back(i);
      B[i] = 1;
    }
  }

  cout << C.size() << endl;
  if (C.size()){
    REP(i, C.size()) cout << C[i] << " ";
    cout << endl;
  }


  return 0;
}
