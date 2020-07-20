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

    ll N, H;
    cin >> N >> H;
    vector<ll> A(N) , B(N);
    REP(i, N) cin >> A[i] >> B[i];

    sort(A.begin(), A.end(), std::greater<ll>());
    sort(B.begin(), B.end(), std::greater<ll>());

    ll tmp = A[0];
    ll s = 0;
    int cnt = 0;
    REP(i, N){
        if (B[i] > tmp && s < H) {
            s += B[i];
            cnt++;
            }
        else break;
    }
    if (s < H){
        cnt += ceil((double)(H - s) / (double) tmp);
    }
    cout << cnt << endl;
    

    return 0;
}