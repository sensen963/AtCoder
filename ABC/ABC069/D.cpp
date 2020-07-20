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
    int H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    vector<vector<int>> c(H, vector<int>(W));

    int k = 1;
    int count = 0;
    REP(i, H) REP(j, W){
        c[i][j] = k;
        count++;
        if (count >= a[k-1]) {
            k++;
            count = 0;
        }
    }
    REP(i, H){
        if (i % 2 == 0){
            REP(j, W) cout << c[i][j] << " ";
        }
        else for(int j = W-1; j >= 0; j--) cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}
