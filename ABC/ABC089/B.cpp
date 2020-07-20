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

    int N;
    cin >> N;
    char c;
    vector<bool> v(4, false);
    REP(i, N){
        cin >> c;
        if(c == 'P') v[0] = true;
        else if (c == 'Y') v[1] = true;
        else if (c == 'G') v[2] = true;
        else if (c == 'W') v[3] = true;
    }

    if (v[0] && v[1] && v[2] && v[3]) cout << "Four" << endl;
    else cout << "Three" << endl;

    return 0;
}