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
    int N;
    cin >> N;
    vector<int> L(N);
    REP(i, N) cin >> L[i];

    sort(L.begin(), L.end());
    ll ans = 0;
    REP(i, N) REP(j, i){
        auto iter1 = lower_bound(L.begin(), L.end(), abs(L[i] - L[j] + 1));
        auto iter2 = upper_bound(L.begin(), L.end(), L[i] +L[j] - 1);
        int tmp = 0;
        if (iter1 - L.begin() <= i && i < iter2 - L.begin()) tmp++;
        if (iter1 - L.begin() <= j && j < iter2 - L.begin()) tmp++;
        ans += iter2 - iter1 - tmp;
        //cout << to_string(i) + " " + to_string(j) + " :" << (iter1 - L.begin()) << " " << (iter2 - L.begin()) << " " << tmp << endl;
    }
    ans /= 3;

    cout << ans << endl;

    return 0;
}