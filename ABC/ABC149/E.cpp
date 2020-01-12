/*

I give up

*/


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

vector<ll> A;
ll N;

ll lower_comb(ll K){

    ll comb = 0, tmp = 2 * A[0];

    int j = 0;
    while(tmp >= K && j != N - 1){
        tmp -= A[j++];
        tmp += A[j];
    }
    if (tmp < K) {
        if (j != 0) tmp = tmp - A[j] + A[j-1];
        j--;
    }
    if (j < 0) return 0;
    tmp -= A[0];
    //cout << tmp  << " " << j << endl;

    REP(i, N){
        tmp += A[i];
        while(true){
            if (tmp >= K) break;
            if (j == 0) return comb;
            tmp = tmp - A[j] + A[j - 1];
            j--;
        }
        comb += j + 1;
        tmp -= A[i];
    }
    return comb;
}

ll solve(ll K, ll C){
    ll ans = 0;
    vector<ll> S(N);
    S[0] = A[0];
    REP(i, N-1) S[i+1] = S[i] + A[i+1];
    //REP(i, N) cout << S[i];


    ll comb = 0, tmp = 2 * A[0];

    int j = 0;
    while(tmp >= K && j != N - 1){
        tmp -= A[j++];
        tmp += A[j];
    }
    if (tmp < K) {
        if (j != 0) tmp = tmp - A[j] + A[j-1];
        j--;
    }
    if (j < 0) return 0;
    tmp -= A[0];
    //cout << tmp  << " " << j << endl;

    REP(i, N){
        tmp += A[i];
        while(true){
            if (tmp >= K) break;
            if (j == 0) return ans;
            //cout << i << " " << j << " " << tmp << endl;
            tmp = tmp - A[j] + A[j - 1];
            //cout << i << " " << j << " " << tmp << endl;
            j--;
        }
        ans += (j + 1) * A[i] + S[j];
        C -= j + 1;
        //cout << "ans:"<< i << " " << j << " " << ans << " " << C << endl;
        if (C == 0) break;
        tmp -= A[i];
    }
    return ans;


}

int main() {

    ll M;
    cin >> N >> M;
    ll a;
    REP(i, N) {
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end(), greater<ll>());
    //REP(i, N) cout << A[i];

    ll r = 2 * A[0];
    ll l = 0;
    ll tmp;
    //cout << lower_comb(103) << endl;
    while(r - l > 1){
        tmp = (l + r ) / 2;
        if (lower_comb(tmp) >= M) l = tmp;
        else r = tmp;
        //cout << l << " " << r << endl;
    }
    //cout << l << endl;
    tmp = lower_comb(l);

    cout << solve(l, M) << endl;

    return 0;
}