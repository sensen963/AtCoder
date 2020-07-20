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
    int sum = 0;
    int inc = 0;
    s = "0" + s;
    for(int i = n; i >= 1; i--){
        int tmp = (s[i] - '0') + inc;
        if (tmp == 5){
            int tmp1 = (s[i-1] - '0');
            inc = (tmp1 >= 5) ? 1 : 0;
            sum += 5;
        }
        else if (tmp >= 6){
            inc = 1;
            sum += 10 - tmp;
        }else{
            inc = 0;
            sum += tmp;
        }
    }
    if (inc == 1) sum++;

    cout << sum << endl;

    return 0;
}

