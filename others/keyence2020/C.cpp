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

    ll N, K, S;
    cin >> N >> K >> S;

    vector<ll> A(N);
    REP(i, K) A[i] = S;
    if (S != 1e9) for(int i = K; i < N; i++) A[i] = S+1;
    else for(int i = K; i < N; i++) A[i] = S-1;

    REP(i, N) cout << A[i] << " ";
    cout << endl;



    return 0;
}
