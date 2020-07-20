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
#include <fstream>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, init, n) for(ll i = init; i <(ll)(n); i++)


ll pl(ll xx, ll target, vector<ll>& A){
    ll l = 0;
    ll hoge = A[xx];
    ll r = A.size();
    if (hoge * A[0] > target) return 0;
    if (hoge * A[r-1] <= target) return (r-1);
    while(r - l > 1){
        ll tmp = (r + l) / 2;
        if (A[tmp] * hoge - target <= 0) l = tmp;
        else r = tmp;
    }
    if (hoge <= A[l]) l--;
    return (l + 1);
}


ll ml(ll xx, ll target, vector<ll>& A){
    ll l = 0;
    ll hoge = A[xx];
    ll r = A.size();
    if (hoge * A[r-1] > target) return 0;
    if (hoge * A[0] <= target) return (r-1);
    while(r - l > 1){
        ll tmp = (r + l) / 2;
        if (A[tmp] * hoge > target) l = tmp;
        else r = tmp;
    }
    if (hoge >= A[r]) r++;
    return (A.size() - r);
}

int main() {


  //std::ifstream in("sub1_small_15.txt");
  //std::cin.rdbuf(in.rdbuf());

    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    ll l = -1e18 * 2;
    ll r = 1e18 * 2;
    while(r - l > 1){
        
        ll tmp = (l + r) / 2;
        ll s = 0;
        REP(i, N){
            if (A[i] >= 0) s += pl(i, tmp, A);
            else s += ml(i, tmp, A);
        }
        //cout << l << " " << r  << " " << tmp << " " << (s/2) << endl;
        if (s % 2 != 0){
            //cout << l << " " << r  << " " << tmp << " " << (s/2) << endl;
            return 0;
        }
        if (s/2 < K) l = tmp;
        else r = tmp;
    }
    //cout << l << " " << r << endl;
    cout << r << endl;

    return 0;
}

