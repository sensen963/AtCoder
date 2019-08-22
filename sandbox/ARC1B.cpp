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

    int A, B;
    cin >> A >> B;

    vector<int> dp(41, 1000);
    vector<int> add{1, -1, 5, -5, 10, -10};
    dp[A] = 0;
    REP(i, 41)REP(j, 41){
        if (dp[j] == 1000) continue;
        for(auto tmp : add){
            if (0 <= j + tmp && j + tmp <= 40) dp[j + tmp] = min(dp[j + tmp], dp[j] + 1);
        }
    }
    cout << dp[B] << endl;


    return 0;
}