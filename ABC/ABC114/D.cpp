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

vector<int> to_prime(int n){
    vector<int> v;
    int tmp = n;
    REP(i, n+1){
        if (i < 2) continue;
        while(tmp % i == 0){
            v.push_back(i);
            tmp /= i;
        }
        if (tmp == 1) break;
    }
    return v;
}

int main() {

    int N;
    cin >> N;
    vector<int> tmpv;
    vector<int> v(102, 0);
    REP(i, N+1){
        if (i < 2) continue;
        tmpv = to_prime(i);
        REP(j, tmpv.size()) v[tmpv[j]]++;
    }
    int tmp2 = 0, tmp4 = 0;
    int tmp14 = 0, tmp24 = 0, tmp74 = 0;
    REP(i, 102){
        if (v[i] >= 4) tmp4++;
        if (v[i] >= 2) tmp2++;

        if (v[i] >= 14) tmp14++;
        if (v[i] >= 24) tmp24++;
        if (v[i] >= 74) tmp74++;
    }
    //REP(i, v.size()) cout << v[i] << " ";
    ll ans = 0;
    ans += (tmp2 - 2) * (tmp4 * (tmp4 - 1)) / 2;
    ans += (tmp4 - 1) * tmp14 + (tmp2 - 1) * tmp24 + tmp74;

    cout << ans << endl;

    return 0;
}