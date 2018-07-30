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
  cin >> N;
  vector<ll> A(N);
  int count = N;
  for(int i = 0; i < N; i++) cin >> A[i];
  int tmp;
  ll lltmp, lltmp1;
  for(int i = 0; i < N;){
    tmp = i;
    lltmp = A[i];
    while(true){
      tmp++;
      if (tmp == N) {
        if (tmp - i > 1) {
          count += (tmp - i) * (tmp - i - 1) / 2;
          i = tmp;
        }else{
          i = tmp;
        }
        break;
      }
      lltmp1 = lltmp ^ A[tmp];
      if (lltmp1 == lltmp + A[tmp]){
        lltmp = lltmp1;
      }else{
        if (tmp - i > 1) {
          count += (tmp - i) * (tmp - i - 1) / 2;
          cout << (tmp - i) << endl;
          i = tmp - 1;
        }else{
          i = tmp;
        }
        break;
      }
    }
  }

  cout << count << endl;
  return 0;
}
