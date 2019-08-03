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
#include <cmath>

using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  ll N, K;
  cin >> N >> K;
  double val = 0;
  vector<ll> d(N);
  int maxt;
  REP(i, N){
    ll j = i + 1;
    ll count = 0;
    while(j < K) {
      j *= 2;
      count++;
    }
    if (i == 0) maxt = count;
    d[i] = count;
    val += pow(2, maxt - count);
    //cout << count;
  }

  val /= (double)N;
  val /= (double)pow(2, maxt);

  cout << val << endl;
  //printf("%.12f\n", val);
  return 0;

}
