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

    ll K, N;
    cin >> K >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    ll tmp = A[0] + K - A[N-1];
    REP(i, N-1) tmp = max(tmp, A[i+1] - A[i]);
    cout << (K - tmp) << endl;
    return 0; 
}
