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
    string s, t;
    cin >> s;
    cin >> t;

    for(int i = s.size() - t.size(); i >= 0; i--){
        string tmp = s.substr(i, t.size());
        bool flag = true;
        REP(j, t.size()){
            if (!(tmp[j] == '?' || tmp[j] == t[j])) flag = false;
        }
        if (!flag) continue;
        REP(j, s.size()){
            if (i <= j && j < i + t.size()) cout << t[j - i];
            else if(s[j] == '?') cout << 'a';
            else cout << s[j];
        }
        cout << endl;
        return 0;
    }
    cout << "UNRESTORABLE" << endl;

    return 0;
}