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
    int N;
    cin >> N;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];
    a.push_back(N + 100);
    ll ans = 0;
    ll tmp = 0;
    REP(i, N+1){
        if(a[i] == i + 1){
            tmp++;
        }
        else{
            if(tmp == 1){
                ans++;
            }
            else if(tmp > 1){
                ans += (tmp % 2 == 0) ? tmp / 2 : tmp / 2 + 1;
            }
            tmp = 0;
        }
    }
    cout << ans << endl;

    return 0;
}
