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

    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<ll> L(K), R(K);
    ll cnt = 0;
    for(int i = 0; i < N && cnt < K; i++){
        if (S[i] == 'o'){
            L[cnt++] = i;
            i += C;
        } 
    }
    cnt = K - 1;
    for (int i = N - 1; i >= 0 && cnt >= 0; i--){
        if (S[i] == 'o'){
            R[cnt--] = i;
            i -= C;
        }
    }
    REP(i, K) if (L[i] == R[i]) cout << (L[i] + 1) << endl;

    return 0;
}