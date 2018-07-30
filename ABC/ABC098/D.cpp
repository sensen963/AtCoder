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
  ll count = 0;
  for(int i = 0; i < N; i++) cin >> A[i];

  int tmp = 0;
  ll lltmp, lltmp1;
  lltmp = 0;
  for(int i = 0; i < N; i++){
    // tmp = i;
    // lltmp = A[i];
    while(true){
      // tmp++;
      if (tmp == N) {
        // if (tmp - i > 1) {
        //   count += (tmp - i) * (tmp - i - 1) / 2;
        //   i = tmp;
        // }else{
        //   i = tmp;
        // }
        // break;
        count += tmp - i;
        lltmp -= A[i];
        break;
      }
      lltmp1 = lltmp ^ A[tmp];
      if (lltmp1 == lltmp + A[tmp]){
        lltmp = lltmp1;
        tmp++;
      }else{
        count += tmp - i;
        if (i == tmp) {
          tmp++;
        }else{
          lltmp -= A[i];
        }
        break;
      }
    }
  }

  cout << count << endl;
  return 0;
}
