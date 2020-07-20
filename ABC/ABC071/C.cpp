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
    ll tmp;
    map<ll, ll> m;
    REP(i, N){
        cin >> tmp;
        m[tmp]++;

    }
    ll a = 0, b = 0;
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if (iter->second < 2) continue;
        if (iter->first > a) {
            if (iter->second >= 4) b = iter->first;
            else b = a;
            a = iter->first;
        }
        else if (iter->first > b) b = iter->first;
    }
    cout << (a * b) << endl;

    return 0;
}