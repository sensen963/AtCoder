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

//set<int> visited;

void dfs(vector<set<int>> V, vector<int>& t_list, int from, set<int>& visited){
//void dfs(vector<set<int>> V, vector<int> t_list, int from){
    visited.insert(from);
    //cout << visited.size() << endl;
    for(auto go_cand : V[from]){
        if (visited.find(go_cand) == visited.end()) {
            //cout <<  from << " " << go_cand << endl;
            dfs(V, t_list, go_cand, visited);
        }
    }
    t_list.push_back(from);
    //cout << t_list.size() << endl;
}

int main() {
    int N;
    cin >> N;
    vector<set<int>> V(N * N + 1);
    set<int> begins;

    int tmp, tmp1;
    REP(i, N) {
        REP(j, N - 1){
            cin >> tmp;
            tmp--;
            tmp = i < tmp ? (i * N + tmp) : (tmp * N + i); 
            cout << tmp << endl;
            if (j == 0) begins.insert(tmp);
            if (j != 0 && begins.find(tmp) != begins.end()) begins.erase(tmp);
            if (j != 0) {
                V[tmp1].insert(tmp);
                //cout << tmp1 << " " << tmp << endl;
            }
        tmp1 = tmp;
        }
    }
    //cout << begins.size() << endl;
    //for(auto hoge : begins) cout << *begins.begin() << " ";
    vector<int> t_list;
    set<int> visited;
    for(auto hoge : begins){
        dfs(V, t_list, hoge, visited);
    }
    //for(auto hoge : t_list) cout << hoge << " ";
    //for(auto hoge : visited) cout << hoge << " ";

    reverse(t_list.begin(), t_list.end());
    //for(auto hoge : t_list) cout << hoge << " ";
    
    // 閉路確認
    /*
    set<int> already;
    for(auto from : t_list){
        already.insert(from);
        for(auto to : V[from]){
            if (already.find(to) != already.end()){
                cout << -1 << endl;
                return 0;
            }
        }
    }
*/ 
    set<int> already;
    int len_max = 0;   
    vector<int> len(t_list.size(), 1);
    for(auto from : t_list){
        already.insert(from);
        for(auto to : V[from]){
            if (already.find(to) != already.end()){
                //cout << from << " "  << to << endl;
                cout << -1 << endl;
                return 0;
            }
            len[to] = len[from] + 1;
            len_max = max(len_max, len[to]);
        }
    }
    cout << len_max << endl;
    return 0;
}
