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


int main() {
    int N;
    cin >> N;
    int NN = N * (N - 1) / 2;
    vector<vector<int>> V(NN);
    set<int> begins;
    map<int, int> m;
    int iter = 0;
    REP(i, N) REP(j, N){
        if (i < j) m[i * N + j] = iter++; 
    }
    int tmp, tmp1;
    vector<int> ine(NN, 0);
    REP(i, N) {
        REP(j, N - 1){
            cin >> tmp;
            tmp--;
            tmp = i < tmp ? (i * N + tmp) : (tmp * N + i);
            tmp = m[tmp];
            //cout << tmp << endl;
            if (j != 0) {
                V[tmp1].push_back(tmp);
                ine[tmp]++;
                //cout << tmp1 << " " << tmp << endl;
            }
        tmp1 = tmp;
        }
    }
    //for(auto tmp : m) cout << tmp.first << " " << tmp.second << endl;
    vector<int> st, t_list;
    REP(i, NN) if(ine[i] == 0) st.push_back(i);
    while(st.size() > 0){
        vector<int> st1;
        for(auto tmp : st){
            t_list.push_back(tmp);
            for (auto hoge : V[tmp]) {
                ine[hoge]--;
                if (ine[hoge] == 0) st1.push_back(hoge);
            }
        ine[tmp] = -1;
        }
        st = st1;
    }
    //for(auto tmp : t_list) cout << tmp << " ";
    if (t_list.size() != N * (N  - 1) / 2){
        cout << -1 << endl;
        return 0;
    }
    int mm = 0;
    vector<int> len(NN, 1);
    REP(i, NN){
        int iter = t_list[i];
        for(auto tmp : V[iter]){
            //cout << iter << " " << tmp << endl;
            len[tmp] = max(len[tmp], len[iter] + 1);
            mm = max(len[tmp], mm);
            //cout << tmp << " " << len[tmp] << endl;

        }
    }
    cout << mm << endl;

    return 0;
}
