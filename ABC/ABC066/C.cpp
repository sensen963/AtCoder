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
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> B(N);
    bool f = (N % 2 == 0) ? true: false;
    REP(i, N / 2) B[i] = A[N - 1 - 2 * i];
    if (!f) {
        B[N / 2] = A[0];
        rep(i, 0, N / 2) B[N / 2 + 1 + i] = A[2 * i + 1];
    }else{
        rep(i, 0, N / 2) B[N / 2 + i] = A[2 * i];
    }

    REP(i, N) cout << B[i] << " ";
    cout << endl; 
    return 0;
}