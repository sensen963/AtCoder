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
#include <chrono>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

void visit(vector<vector<int>>& c, int i, int j, int n, set<int>& checked){
    if(checked.find(i*(n+2)+j) != checked.end()){
        return;
    }
    checked.insert(i*(n+2)+j);
    rep(ii, -1, 2)rep(jj, -1, 2){ 
        if (ii * jj != 0 || (ii+jj == 0)) continue;
        if(c[i][j] == c[i+ii][j+jj]) visit(c, i+ii, j+jj, n, checked);
    }
}

bool check_connect(vector<vector<int>>& c, vector<set<int>>& color, int n, int target){
    set<int> checked;
    int first = *color[target].begin();
    visit(c, first/(n+2), first%(n+2), n, checked);
    return color[target].size() == checked.size();
}

bool check_cmatrix(vector<vector<int>>& matrix, vector<vector<int>>& c, vector<set<int>>& color, int n,int m, int target){
    vector<int> cmatrix(m+1, 0);
    for(auto iter: color[target]){
        rep(ii, -1, 2)rep(jj, -1, 2){ 
            if (ii * jj != 0) continue;
            int hoge = iter/(n+2)+ii;
            int hoge1 = (iter%(n+2))+jj;
            int hoge2 = c[iter/(n+2)+ii][(iter%(n+2))+jj];
            cmatrix[c[iter/(n+2)+ii][(iter%(n+2))+jj]] = 1;
        }
        
    }
    REP(i, m+1) if(cmatrix[i] != matrix[target][i]) return false;
    return true;
}

bool check_other_color(vector<vector<int>>& matrix, vector<vector<int>>& c, vector<set<int>>& color, int i, int j, int n,int m, int target){
    rep(ii, -1, 2)rep(jj, -1, 2){ 
        if (ii * jj != 0 || (ii+jj == 0)) continue;
        if (c[i+ii][j+jj] == 0 || c[i+ii][j+jj] == target) continue;
        if (!check_cmatrix(matrix, c, color, n, m, c[i+ii][j+jj])) return false;
    }
    return true;
}

int main() {
    chrono::system_clock::time_point start, end;
    
    srand(1);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> c(n+2, vector<int>(n+2, 0));
    vector<vector<int>> r(m+1, vector<int>(m+1, 0));
    REP(i, n) REP(j, n) cin >> c[i+1][j+1];
    start = chrono::system_clock::now();
    vector<set<int>> color(m+1);
    rep(i, 1, n+1)rep(j, 1, n+1){
        color[c[i][j]].insert((n+2)*i+j);
        rep(ii, -1, 2)rep(jj, -1, 2){ 
            if (ii * jj != 0) continue;
            r[c[i][j]][c[i+ii][j+jj]] = 1;
            r[c[i+ii][j+jj]][c[i][j]] = 1;
        }
    }
/*
    rep(i, 1, n+1)rep(j, 1, n+1){
        int tmp = c[i][j];
        bool hoge = false;
        if(color[tmp].size() == 1) continue;
        rep(ii, -1, 2)rep(jj, -1, 2){ 
            if (ii * jj != 0) continue;
            if (c[i+ii][j+jj] == 0) hoge = true;
        }
        if (!hoge) continue;

        c[i][j] = 0;
        color[tmp].erase(i*(n+2)+j);
        if (!(check_connect(c, color, n, tmp) &&check_cmatrix(r, c, color, n, m, tmp) &&check_other_color(r, c, color, i ,j, n, m, tmp))){
        //if (!(check_connect(c, color, n, tmp) &&check_cmatrix(r, c, color, n, m, tmp))){
            c[i][j] = tmp;
            color[tmp].insert(i*(n+2)+j);
        }
    }
*/
    int count = 0;
    while(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() < 1950){
        int i = rand() % n + 1;
        int j = rand() % n + 1;
        int tmp = c[i][j];
        bool next0 = false;
        if( c[i][j] == 0 || color[tmp].size() == 1) continue;
        rep(ii, -1, 2)rep(jj, -1, 2){ 
            if (ii * jj != 0) continue;
            if (c[i+ii][j+jj] == 0) next0 = true;
        }
        if (next0) {
            c[i][j] = 0;
            color[tmp].erase(i*(n+2)+j);
            if (!(check_connect(c, color, n, tmp) &&check_cmatrix(r, c, color, n, m, tmp) &&check_other_color(r, c, color, i ,j, n, m, tmp))){
        //if (!(check_connect(c, color, n, tmp) &&check_cmatrix(r, c, color, n, m, tmp))){
                c[i][j] = tmp;
                color[tmp].insert(i*(n+2)+j);
            }
            continue;
        }
        int rand_tmp = rand() % 4;
        int rand_ii, rand_jj;
        switch (rand_tmp)
        {
            case 0:
                rand_ii = 0, rand_jj = -1;
                break;
            case 1:
                rand_ii = -1, rand_jj = 0;
                break;
            case 2:
                rand_ii = 1, rand_jj = 0;
                break;
            case 3:
            rand_ii = 0, rand_jj =1;
            break;
        default:
            break;
        }
        if(c[i][j] == c[i+rand_ii][j+rand_jj]||c[i+rand_ii][j+rand_jj]==0) continue;
            c[i][j] = c[i+rand_ii][j+rand_jj];
            color[tmp].erase(i*(n+2)+j);
            color[c[i+rand_ii][j+rand_jj]].insert(i*(n+2)+j);
            if (!(check_connect(c, color, n, tmp) &&check_cmatrix(r, c, color, n, m, tmp) &&check_other_color(r, c, color, i ,j, n, m, tmp)&&check_cmatrix(r, c, color, n, m, c[i+rand_ii][j+rand_jj]) &&check_other_color(r, c, color, i+rand_ii ,j+rand_jj, n, m, c[i+rand_ii][j+rand_jj]))){
        //if (!(check_connect(c, color, n, tmp) &&check_cmatrix(r, c, color, n, m, tmp))){
                c[i][j] = tmp;
                color[tmp].insert(i*(n+2)+j);
                color[c[i+rand_ii][j+rand_jj]].erase((i)*(n+2)+j);

            }
    count++;
    if(count%100==0){
rep(i, 1, n+1){
        rep(j, 1, n+1) cout << c[i][j] << " ";
        cout << endl;
    
        }
    }
    }
    rep(i, 1, n+1){
        rep(j, 1, n+1) cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}
