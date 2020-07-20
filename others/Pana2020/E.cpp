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


bool is_match(char a, char b){
    return (a == '?' || b == '?' || a == b);
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    int A = a.size();
    int B = b.size();
    int C = c.size();

    //vector<bool> ab(10000, true);
    //vector<bool> bc(10000, true);
    //vector<bool> ac(10000, true);

    bool ab[10000] = {true};REP(i, 10000) ab[i] = true;
    bool ac[10000] = {true};REP(i, 10000) ac[i] = true;
    bool bc[10000] = {true};REP(i, 10000) bc[i] = true;

    REP(i, A)REP(j, B) if (!is_match(a[i], b[j])) ab[i - j + 5000] = false; 
    REP(i, A)REP(j, C) if (!is_match(a[i], c[j])) ac[i - j + 5000] = false; 
    REP(i, B)REP(j, C) if (!is_match(b[i], c[j])) bc[i - j + 5000] = false; 
    
    int M = 2001;
    int ans = 3 * M;
    rep(i, -2*M, 2*M)rep(j, -2*M, 2*M)if (ab[i + 5000] && ac[j + 5000] && 0 <= (i - j + 5000) && (i - j + 5000) < 10000  && bc[j - i + 5000]){
        int r = max(A, max(i + B, j + C));
        int l = min(0, min(i, j));
        ans = min(ans, r - l);
    }
    cout << ans << endl;
    return 0;
}
