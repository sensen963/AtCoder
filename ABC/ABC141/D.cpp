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

    ll N, M;
    cin >> N >> M;
    priority_queue<ll> A;
    ll a;
    REP(i, N){
        cin >> a;
        A.push(a);
    }
    REP(i, M){
        ll t = A.top();
        A.pop();
        t = ll(t / 2);
        A.push(t);
    }
    ll sum = 0;
    while(!A.empty()){
        sum += A.top();
        A.pop();
    } 


    cout << sum <<endl;


    return 0;
}