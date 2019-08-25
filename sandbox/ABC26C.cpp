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

int ans(vector<set<int>> a, int i){
    if (a[i].empty()) return 1;
    set<int> au;
    int b, c, tmp1;
    for(auto tmp : a[i]){
        tmp1 = ans(a, tmp);
        if (tmp == *a[i].begin()){
            b = tmp1;
            c = tmp1;
        }else{
            b = max(b, tmp1);
            c = min(c, tmp1);
        }
    }
    return (b + c + 1);
}

int main() {
    int N;
    cin >> N;
    int tmp;
    vector<set<int>> child(N);
    REP(i, N - 1){
        cin >> tmp;
        child[tmp - 1].insert(i + 1);
    }
    cout << ans(child, 0) << endl;

    return 0;
}
