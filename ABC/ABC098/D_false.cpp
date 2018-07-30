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
  vector<int> q(N);
  int count = N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N-1; i++){
    if ((A[i] ^ A[i+1]) == (A[i] + A[i+1])){
      q[i] = 1; // 隣と成立するか
      count++;
    }
  }

  int tmp = 0;
  for(int i = 0; i < N-1; i++){
    if (q[i] == 1){
      tmp = i;
      while(true){
        tmp++;
        if((q[tmp] == 1) && ((A[i] ^ A[tmp]) == (A[i] + A[tmp]))) {
        }else{
          if (tmp - i > 1){
            count += (tmp - i) * (tmp - i - 1) / 2;
          }else{
            //count++;
          }
          if (q[tmp] == 1){
            i = tmp - 2;
          }else{
            i = tmp - 1;
          }
          break;
        }

      }
    }
  }


  for(int i = 0; i < N; i++) cout << q[i] << endl;

  cout << count << endl;
  return 0;
}
