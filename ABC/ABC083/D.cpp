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

    string s;
    cin >> s;
    int n = s.size();
    char c;
    int ans = 0;
    if (n % 2 == 0){
        c = s[n / 2];
        int i = 1;
        while(i <= n / 2 && s[n / 2 - i] == c && s[n / 2 - 1 + i] == c) i++;
        i--;
        ans = (n / 2) + i;
    }else{
        c = s[n / 2];
        int i = 0;
        while(i <= n / 2 && s[n / 2 - i] == c && s[n / 2 + i] == c) i++;
        i--;
        ans = (n / 2) + 1 + i;
    }
    cout << ans << endl;

    return 0;
}
