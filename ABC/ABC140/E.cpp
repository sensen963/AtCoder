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
    vector<int> P(N), R(N);

    REP(i, N) {
        cin >> P[i];
        P[i]--;
        R[P[i]] = i;
    }

    vector<vector<int>> big(N, vector<int>(4));
    set<int> cul;
    ll sum = 0;

    for(int i = N - 1; i >= 0; i--){
        int ii = R[i];
        cul.insert(ii);
        auto iter = cul.find(ii);
        if (iter == cul.begin()){
            big[i][0] = -1;
            big[i][1] = -1;
        }else{
            big[i][0] = *(--iter);
            if (iter == cul.begin()) big[i][1] = -1;
            else big[i][1] = *(--iter);
        }

        iter = cul.find(ii);
        if (++iter == cul.end()){
            big[i][2] = N;
            big[i][3] = N;
        }else{
            big[i][2] = *iter;
            if (++iter == cul.end()) big[i][3] = N;
            else big[i][3] = *iter;
        }
        ll tmp1 = big[i][0] - big[i][1];
        tmp1 *= (big[i][2] - ii);
        ll tmp2 = (big[i][3] - big[i][2]);
        tmp2 *= (ii - big[i][0]);

        sum += (i + 1) * (tmp1 + tmp2);
    }
/*
    REP(i, N){
        cout << i << ": ";
        REP(j, 4) cout << big[i][j] << " ";
        cout << endl;
    }
*/
    cout << sum << endl;

    return 0;
}