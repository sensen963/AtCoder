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
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    REP(i, N) cin >> P[i];
    REP(i, N) cin >> Q[i];

    vector<int> v(N);
    iota(v.begin(), v.end(), 1);  

    int a = -1, b = -1;
    //REP(i, N) cout << v[i] <<endl;
    for(int i = 0;;i++){
        bool o = true;
        REP(i, N) if (v[i] != P[i]) {
            o = false;
            break;
        }
        if (o) a = i;

        o = true;
        REP(i, N) if (v[i] != Q[i]) {
            o = false;
            break;
        }
        if (o) b = i;
        if (a >= 0 && b >= 0) break;

        next_permutation(v.begin(), v.end());
    }
    //cout << a << " " << b << endl;
    cout << abs(a - b) << endl;


    return 0;
}