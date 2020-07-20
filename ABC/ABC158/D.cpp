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
    int Q;
    cin >> s;
    cin >> Q;
    bool ish = true;
    int mode, mode1;
    char c;
    string f = "";
    string b = ""; 
    REP(i, Q){
        cin >> mode;
        if (mode==1) ish ^= true;
        else {
            cin >> mode1;
            cin >> c;
            if ((mode1 == 1) ^ !ish) f += c;
            else b += c;
        }
    }
    reverse(f.begin(), f.end());
    s = f + s + b;
    if (!ish) reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
