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

  ll N;
   cin >> N;

   vector<ll> A(N);
   ll tmp_odd = 0;
   ll tmp_even = 0;
   REP(i, N){
     cin >> A[i];
     if (i == N - 1) continue;
     else if (i % 2 == 0) tmp_even += A[i];
     else tmp_odd += A[i];
   }
   ll tmp1 = tmp_even - tmp_odd + A[N- 1];
   REP(i, N){
     if (i == 0) cout << tmp1;
     else {
       tmp1 = 2 * A[i - 1] - tmp1;
       cout << " " << tmp1;
     }
   }
   cout << endl;

  return 0;
}
