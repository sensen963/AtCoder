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

    ll N;
    cin >> N;
    vector<ll> A(N+1, 0);
    REP(i, N) cin >> A[i+1];

    vector<ll> d(N+1);
    REP(i, N) d[i] = abs(A[i+1] - A[i]);
    ll sum = abs(A[N]);
    d[N] = sum;
    REP(i, N) sum += d[i];

    ll tmp;
    rep(i, 1, N+1){
        if ((A[i-1] < A[i] && A[i] < A[i+1]) || (A[i+1] < A[i] && A[i] < A[i-1])) tmp = sum;
        else tmp = sum - 2 * min(d[i-1], d[i]);
        cout << tmp << endl;

    }
    return 0;
}
