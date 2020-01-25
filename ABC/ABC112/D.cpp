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


int main() {

    ll N, M;
    cin >> N >> M;

    ll tmp1 = 1, tmp2 = M, tmp3 = 1;
    while(tmp1 * tmp1 <= M){
        if (M % tmp1 == 0) {
            tmp2 = M / tmp1;
            if(tmp1 >= N) tmp3 = max(tmp3, tmp2);
            if(tmp2 >= N) tmp3 = max(tmp3, tmp1);
        }
        tmp1++;
    }
    cout << tmp3 << endl;
    return 0;
}