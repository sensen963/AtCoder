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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    int count = 0;
    ll tmp = K;
    while(tmp > 0){
        tmp /= 2;
        count++;
    }
    vector<int> C(100, 0);
    for(auto a : A){
        tmp = a;
        for(int i = 0; tmp > 0; i++){
            if(tmp % 2 == 1) C[i]++;
            tmp /= 2;
        }
    }
    ll ans = 0;
    
    for(int i = count - 1; i >= 0; i--){
        if (2 * C[i] < N && ans + pow(2, i) <= K) ans += pow(2, i); 
    }
    //cout << count << endl;
    //cout << ans << endl;
    ll ans1 = 0;
    REP(i, N) ans1 += ans ^ A[i];
    cout << ans1 << endl;


    return 0;
}