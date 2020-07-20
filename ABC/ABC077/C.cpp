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
typedef pair<ll, ll> P;

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
    vector<ll> A(N), B(N), C(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll tmp = 0;
    vector<ll> cumlA(N), cumlB(N);
    REP(i, N){
        while(tmp < N && A[tmp] < B[i])tmp++;
        cumlA[i] = tmp;
    }
    tmp = 0;
    ll hoge = 0;
    REP(i, N){
        while(tmp < N && B[tmp] < C[i]){
            hoge += cumlA[tmp];
            tmp++;
        }
        cumlB[i] = hoge;
    }
    ll ans = 0;
    REP(i, N) ans += cumlB[i];
    cout << ans << endl;
    return 0;
}