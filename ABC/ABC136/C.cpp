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
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    REP(i, N) cin >> H[i];

    for(ll i = N - 2; i >= 0; i--){
        if (H[i] - 1 > H[i + 1]) {
            cout << "No" << endl;
            //cout << i;
            return 0;
        }else if (H[i] - 1 == H[i + 1]) H[i]--;
    }
    cout << "Yes" << endl;
    //REP(i, N) cout << H[i];
    return 0;
}
