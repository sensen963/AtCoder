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
    string s;
    cin >> s;
    string ss;
    int tmp = 0;
    for(int i = N - 1; i >= 0; i--){
        if (s[i] == '(' && tmp >= 0) tmp++;
        else if(s[i] == '(' && tmp < 0){
            ss = '(' + ss;
            tmp++;
        }else if(s[i] == ')' && tmp > 0){
            REP(j, tmp) ss = ')' + ss;
            REP(j, tmp) ss = '(' + ss;
            ss = ')' + ss;
            tmp = -1;
        }else {
            tmp--;
            ss = ')' + ss;
        }
    }
    if (tmp < 0) REP(i, abs(tmp)) ss = '(' + ss;
    if (tmp > 0){
        REP(j, tmp) ss = ')' + ss;
        REP(j, tmp) ss = '(' + ss;
    }
    cout << ss << endl;

    return 0;
}
