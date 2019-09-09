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
    vector<int> V(N);
    REP(i, N) cin >> V[i];
    sort(V.begin(), V.end());
    double tmp = V[0];
    REP(i, N - 1) tmp = (tmp + V[i + 1]) / 2.0;
    cout << tmp << endl;
    return 0;
}
