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

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)

ll gcd(ll a, ll b){
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool is_prime(int x){
    double tmp = sqrt(x) + 1;
    if (x == 1) return true;
    REP(i, tmp){
        if (i < 2) continue;
        if (x % i == 0) return false;
    }
    return true; 
}

int main() {

    ll A, B;
    cin >> A >> B;

    ll g = gcd(A, B);
    //double tmp = sqrt(g) + 1;
    ll ans = 1;
    for(ll i = 2; i * i < g; i++){
        if (g % i == 0){
        //cout << i << endl;
            ans++;
            while (g % i == 0) g /= i;
        }
    }
    if (g != 1) ans++;
    cout << ans << endl;


    return 0;
}