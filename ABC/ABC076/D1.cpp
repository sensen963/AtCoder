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
    vector<ll> v(N), t(N);
    REP(i, N) cin >> t[i];
    REP(i, N) cin >> v[i];
    ll total = 0;
    REP(i, N) total += t[i];
    ll tmp = 0;
    
    map<double, double> mf;
    double ii = 0;
    REP(i, N){
        REP(j, 2 * t[i]){
            if (j == 0 && i != 0) mf[ii] = min(v[i-1], v[i]);
            else mf[ii] = v[i];
            ii += 0.5;
        }
    }
    /*
        ii = 0;
    while(ii <= total){
        cout << ii << " " << mf[ii] << endl;
        ii += 0.5;
    }
    */
    mf[total] = 0;
    double current = 0;
    ii = total - 0.5;
    while(ii >= 0){
        if (mf[ii] > current){
            current += 0.5;
            mf[ii] = current;
        }else{
            current = mf[ii];
        }
        ii -= 0.5;
    }
    /*
    ii = 0;
    while(ii <= total){
        cout << ii << " " << mf[ii] << endl;
        ii += 0.5;
    }
*/
    //REP(i, total+1) cout << i << " " << m[i] << endl;
    double cur = 0;
    ii = 0.5;
    map<double, double> act;
    act[0] = 0;

    while(ii < 2 * total){
        if (cur < mf[ii]){
            cur += 0.5;
            act[ii] = cur;
        }else{
            act[ii] = mf[ii];
            cur = mf[ii];
        }
        ii += 0.5;
    }
    /*
    ii = 0;
    while(ii <= total){
        cout << ii << " " << act[ii] << endl;
        ii += 0.5;
    }
    */
    
    //REP(i, total+1) cout << i << " " << act[i] << endl;
    double ans = 0;
    ii = 0;
    while(ii < 2 * total){
        ans += (double)(act[ii] + act[ii+0.5]) / 4.0;
        ii += 0.5;
    } 
    printf("%.4f\n", ans);


    return 0;
}