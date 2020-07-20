
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
typedef pair<int, char> P;
#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    int N, M;
    cin >> N >> M;
    vector<P> r(M);
    int a;
    char b;
    REP(i, M){
        cin >> a;
        cin >> b;
        a--;
        r[i].first = a;
        r[i].second = b;
    }
    int s, t;
    if (N == 1){
        s = 0;
        t = 10;
    }else if (N == 2){
        s = 10;
        t = 100;
    }else{
        s = 100;
        t = 1000;
    }
    bool f = false;
    rep(i, s, t){
        f = false;
        string s = to_string(i);
        REP(j, M) if (s[r[j].first] != r[j].second) {
            f = true;
            break;
        }
        if (f) continue;
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}

