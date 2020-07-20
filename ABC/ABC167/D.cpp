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

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }
    if (K <= N){
        ll target = 0;
        REP(i, K){
            target = A[target];
        }
        cout << (target + 1) << endl;
        return 0;
    }
    vector<ll> num(N, -1);
    ll target = 0;
    ll i = 0;
    while(num[target] < 0){
        num[target] = i++;
        target = A[target];
    }
    ll r = i - num[target];
    K = (K - num[target]) % r;
    REP(i, K){
        target = A[target];
    }
    cout << (target + 1) << endl;

    

    return 0;
}