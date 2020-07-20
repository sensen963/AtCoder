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
    vector<set<ll>> v(N);
    int a, b;
    REP(i, N-1){
        cin >> a >> b;
        a--;
        b--;
        v[a].insert(b);
        v[b].insert(a);
    }
    vector<int> d(N, -1), d1(N, -1);
    d[0] = 0;
    d1[N-1] = 0;
    vector<int> tmp, tmp1;
    tmp.push_back(0);
    for(int i = 0; i < tmp.size(); i++){
        int iter = tmp[i];
        for(auto j: v[iter]){
            if (d[j] < 0){
                tmp.push_back(j);
                d[j] = d[iter] + 1;
            }
        }
    }

    tmp1.push_back(N-1);
    for(int i = 0; i < tmp1.size(); i++){
        int iter = tmp1[i];
        for(auto j: v[iter]){
            if (d1[j] < 0){
                tmp1.push_back(j);
                d1[j] = d1[iter] + 1;
            }
        }
    }
    a = 0, b = 0;
    REP(i, N) if (d[i] <= d1[i]) a++; else b++;
    string ans = (a > b) ? "Fennec" : "Snuke";
    cout << ans << endl;

    return 0;
}
