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
typedef pair<ll, ll> P; 

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, init, n) for(ll i = init; i <(ll)(n); i++)

int main() {

    string s;
    cin >> s;
    s += "TTT";
    int x, y;
    cin >> x >> y;

    vector<int> v, u;
    bool up = false;
    int tmp = 0;

    int us = 0, vs = 0;
    REP(i, s.size()){
        if (s[i] == 'F') tmp++;
        else{
            if (up) {u.push_back(tmp); us += tmp;}
            else {v.push_back(tmp); vs += tmp;}
            tmp = 0;
            up ^= true;
        }
    }
    vector<vector<bool>> v1(u.size(), vector<bool>(2 * us + 5, false));
    vector<vector<bool>> v2(v.size(), vector<bool>(2 * vs + 5, false));

    REP(i, v.size()){
        if (i == 0){
            v2[i][v[0] + vs] = true;
        }
        else REP(j, 2 * vs + 4){
            if (v2[i-1][j]){
                v2[i][j - v[i]] = true;
                v2[i][j + v[i]] = true;
            }
        }
    }

    REP(i, u.size()){
        if (i == 0){
            v1[i][u[0] + us] = true;
            v1[i][-u[0] + us] = true;
        }
        else REP(j, 2 * us + 4){
            if (v1[i-1][j]){
                v1[i][j - u[i]] = true;
                v1[i][j + u[i]] = true;
            }
        }
    }

    if (x + vs >= 0 && y + us >= 0  && v2[v.size()-1][x + vs] && v1[u.size()-1][y + us]) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
