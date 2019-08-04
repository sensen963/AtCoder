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
#include <cmath>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
    ll M, K;
    cin >> M >> K;

    if (K >= pow(2, M)){
        cout << -1 << endl;
        return 0;
    }else if (M < 2 && K != 0){
        cout << -1 << endl;
        return 0;
    }else if (M == 1) {
        cout << "0 0 1 1" << endl;
        return 0;
    }
    vector<ll> v;
    v.push_back(K);
    REP(i, 1 << M) if (i != K) v.push_back(i);
    v.push_back(K);
    for(ll i = (1 << M) - 1; i >= 0; i--) if (i != K) v.push_back(i);
    for(auto tmp : v) cout << tmp << " ";
    cout << endl;

    return 0;
}