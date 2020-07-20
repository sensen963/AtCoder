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

using ll = long long;
int ans;
int n, m, q;
vector<vector<int>> tuples;
int num = 0;
void check(vector<int>& a) {
    num++;
    assert((int)a.size() == n+1);
    int tempans = 0;
    for(int i = 0; i < (int)tuples.size(); i++) {
        int ai = tuples[i][0], bi = tuples[i][1], ci = tuples[i][2], di = tuples[i][3];
        if(a[bi]-a[ai] == ci) {
            tempans += di;
        }
    }
    ans = max(ans, tempans);
}

void dfs(vector<int>& cur) {
    if((int)cur.size() == n+1) {
        check(cur);
        return;
    }
    int d = cur.back();
    for(int i = d; i <= m; i++) {
        cur.push_back(i);
        dfs(cur);
        cur.pop_back();
    }
}

int main()
{
    cin >> n >> m >> q;
    tuples.resize(q, vector<int>(4));
    for(int i = 0; i < q; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> tuples[i][j];
        }
    }
    ans = 0;
    vector<int> v = {1};
    dfs(v);
    assert(v == vector<int>{1});
    cout << ans << endl;
    cout << num << endl;
}
