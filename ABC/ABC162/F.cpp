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
    ll N1 = N / 2;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    if (N % 2 == 0){
        ll a = 0, b = 0;
        REP(i, N / 2){
            a += A[i * 2];
            b += A[i * 2 + 1];
        }
        cout << min(a, b) << endl;
        return 0;
    }

    vector<ll>FE(N1+2, 0), FO(N1+2, 0), BE(N1+2, 0), BO(N1+2, 0);
    REP(i, N){
        if (i % 2 == 0) FE[i / 2 + 1] = A[i] + FE[i / 2]; 
        else FO[i / 2 + 1] = A[i] + FO[i / 2]; 
    }
    for(ll i = N - 1; i >= 0; i--){
        if (i % 2 == 0) BE[(N - 1 - i) / 2 + 1] = A[i] + BE[(N-i-1) / 2];
        else BO[(N - 1 - i) / 2 + 1] = A[i] + BO[(N-1-i) / 2];
    }
    ll ans = FE[N1];
    REP(i, N1+1){
        ans = max(ans, FE[i] + BE[N1-i]);
        ans = max(ans, FE[i] + BO[N1-i]);
        ans = max(ans, FO[i] + BE[N1-i]);
        ans = max(ans, FO[i] + BO[N1-i]);
        cout << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

