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
    ll odd = 0, even = 0, quad = 0;
    REP(i, N) {
        cin >> a[i];
        if (a[i] % 2 == 0) even++; else odd++;
        if (a[i] % 4 == 0) quad++;
    }
    even -= quad;
    if (even == 0) quad++;
    if (odd <= quad) cout << "Yes" << endl;
    else cout << "No" << endl;




    return 0;
}
