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
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

map< ll, ll > LCM(map< ll, ll > a, map< ll, ll > b){
    map< ll, ll > m;
    auto i1 = a.begin();
    auto i2 = b.begin();
    while(i1 != a.end() || i2 != b.end()){
        if (i1->first == i2->first){
            m[i1->first] = max(i1->second, i2->second);
            i1++;
            i2++;
        }else if (i2 == b.end() || i1->first < i2->second){
            m[i1->first] = i1->second;
            i1++;
        }else{
            m[i2->first] = i2->second;
            i2++;
        }
    }
    return m;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
    const ll MOD = 1e9 + 7;
    ll N;
    cin >> N;
    vector<ll> v(N);
    vector<map<ll, ll>> m(N+1);
    ll lcm = 1, g, inv = 0;
    REP(i, N){
        cin >> v[i];
        m[i] = prime_factor(v[i]);
        if (i == 0) m[N] = m[0];
        else m[N] = LCM(m[i], m[N]);
    }
    ll mul = 1;
    for(auto iter = m[N].begin(); iter != m[N].end(); iter++){
        REP(i, iter->second) mul = (mul * iter->first) % MOD;
    }

    ll ans = 0;
    REP(i, N){
        inv = mul * modinv(v[i], MOD) % MOD;
        ans = (ans + inv) % MOD;
    }

    cout << ans << endl;


    return 0;
}
