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
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    int ans = 0;
    vector<int> V(N), C(N);
    REP(i, N) cin >> V[i];
    REP(i, N) cin >> C[i];
    REP(i, N) if (V[i] > C[i]) ans += V[i] - C[i];

    cout << ans << endl;

    return 0;
}