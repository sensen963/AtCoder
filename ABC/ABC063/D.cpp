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
#include <fstream>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll> h(N);
    REP(i, N) cin >> h[i];
    sort(h.begin(), h.end());

    ll l = 0, r = 1e9+2;
    while(r - l > 1){
        ll k = (r + l + 1) / 2;
        ll count = 0;
        REP(i, N){
            ll hoge = h[i] - B * k;
            if (hoge > 0) {
                count += hoge / (A - B);
                if ((hoge % (A - B)) != 0) count++;
            }
        }
        if (count > k) l = k;
        else r = k;
    }
    cout << r << endl;


    return 0;
}