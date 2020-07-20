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
    int a = s[0] - '0';
    int b = s[1] - '0';
    int c = s[2] - '0';
    int d = s[3] - '0';
    int op[] = {-1, 1};
    REP(i, 2)REP(j, 2)REP(k, 2){
        if (a + op[i] * b + op[j] * c + op[k] * d == 7){
            char o = i == 0 ? '-' : '+';
            char p = j == 0 ? '-' : '+';
            char q = k == 0 ? '-' : '+';
            printf("%d%c%d%c%d%c%d=7\n", a, o, b, p, c, q, d);
            return 0;
        } 
    }
    

    return 0;
}