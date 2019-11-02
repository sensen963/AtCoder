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

bool is_less_X(vector<ll> A, vector<ll> F, ll K, ll X){
    ll n = A.size();

    ll s = 0;
    REP(i, n){
        s += max(A[i] - floor((double) X / (double) F[i]), 0);
    }
    //cout << X << ": "<< s << endl;
    if (s <= K) return true;
    return false;
}

int main() {

    ll N , K;
    cin >> N >> K;

    vector<ll> A(N), F(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> F[i];

    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());

    ll Xb = 1e12;
    ll Xs = -1;
    ll tmp;
    while(Xb - Xs > 1){
        tmp = (Xb + Xs) / 2;
        if (is_less_X(A, F, K, tmp)) Xb = tmp;
        else Xs = tmp;
        //cout << tmp << endl;
    }
    cout << Xb << endl;

    return 0;
}