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

ll euclidean_gcd(ll a, ll b) {
  if(a < b) euclidean_gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}


int main() {

  ll n, x;
  cin >> n >> x;

  vector<ll> array(n);
  REP(i, n){
    cin >> array[i];
    array[i] = abs(array[i] - x);
    //cout << array[i] << endl;
  }
  ll min_gcd = array[0];
  REP(i, n){
    min_gcd = euclidean_gcd(min_gcd, array[i]);
  }

  cout << min_gcd << endl;

  return 0;
}
