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

void sort2vectors(vector<ll> &av, vector<ll> &bv)
{
        int n = av.size();
        vector<ll> p(n), av2(n), bv2(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](ll a, ll b) { return av[a] < av[b]; });
        for (int i = 0; i < n; i++) {
                av2[i] = av[p[i]];
                bv2[i] = bv[p[i]];
        }
        av = av2;
        bv = bv2;
}

int main() {

  ll N;
  cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N) cin >> A[i] >> B[i];

  sort2vectors(B, A);

  //REP(i, N) cout << A[i] << B[i] <<endl;
  ll cul = 0;
  ll time = 0;
  REP(i, N){
    cul += A[i];
    if (cul > B[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
