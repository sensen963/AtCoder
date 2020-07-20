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
    ll K;
    cin >> K;
    ll k = K / 50;
    ll l = K % 50;
    vector<ll> v(50, 100 - l + k);
    REP(i, 50 - l){
        v[i] -= 51;
    }
    cout << 50 << endl;
    REP(i, 50) cout << v[i] << " ";
    cout << endl;

    return 0;
}