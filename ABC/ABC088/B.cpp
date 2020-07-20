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

    int N;
    cin >> N;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    int b = 0, c = 0;
    REP(i, N) if(i % 2) b += a[i]; else c += a[i];

    cout << abs(b - c) << endl; 

    return 0;
}