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
    int N;
    cin >> N;
    vector<string> s(2);
    cin >> s[0];
    cin >> s[1];

    ll ans = 0;
    int prev, i;
    const ll MOD = 1e9 + 7;

    if (s[0][0] == s[1][0]) {
        ans = 3;
        prev = 0;
        i = 1;
    }
    else{
        ans = 6;
        prev = 1;
        i = 2;
    }
    for(;i < N; i++){
        if(s[0][i] == s[1][i] && prev == 0){
            ans = (ans * 2) % MOD;
            prev = 0;
        }else if (s[0][i] != s[1][i] && prev == 0){
            ans = (ans * 2) % MOD;
            prev = 1;
            i++;
        }else if (s[0][i] == s[1][i] && prev == 1){
            prev = 0;
        }else if (s[0][i] != s[1][i] && prev == 1){
            ans = (ans * 3) % MOD;
            prev = 1;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}