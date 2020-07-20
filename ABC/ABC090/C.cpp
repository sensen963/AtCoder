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
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    ll n, m;
    cin >> n >> m;

    if (n == 1 && m == 1){
        cout << 1 << endl;
    }else if (n == 1){
        cout << (m - 2) << endl;
    }else if (m == 1) cout << (n - 2) << endl;
    else cout << ((n-2)*(m-2)) << endl;
    

    return 0;
}