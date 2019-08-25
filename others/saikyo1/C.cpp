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


int main() {
    ll N;
    string S;
    cin >> N;
    cin >> S;

    const ll MOD = 1e9 + 7;
    ll ans = 1, c = 0;
    REP(i, 2 * N){
        if (S[i] == 'W' ^ c % 2 == 0) c++;
        else{
            ans = (ans * c) % MOD;
            c--;
        }
    }
    if (c != 0) ans = 0;
    REP(i, N) ans = (ans * (i + 1)) % MOD;
    cout << ans << endl;

    return 0;
}