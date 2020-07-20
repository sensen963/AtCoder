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
    vector<int> s(N);
    int sum = 0;
    REP(i, N) {
        cin >> s[i];
        sum += s[i];
    }
    if (sum % 10 != 0){
        cout << sum << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    REP(i, N){
        if (s[i] % 10 != 0){
            cout << (sum - s[i]) << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}