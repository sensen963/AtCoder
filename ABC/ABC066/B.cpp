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

bool odd(string s){
    int n = s.size();
    if (n % 2 == 1) return false;
    n /= 2;
    REP(i, n){
        if (s[i] != s[n + i]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string s1;
    REP(i, n) {
        s1 = s.substr(0, n - 1 - i);
        if (odd(s1)){
            cout << (n - i - 1) << endl;
            return 0;
        }
    }
    return 0;
}