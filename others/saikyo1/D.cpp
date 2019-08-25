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

int REC(vector<vector<int>>& G, vector<int>& input, int num){
    //cout << "Hi" << endl;

    int len = input.size();
    vector<int> a, b;
    a.assign(input.begin(), input.begin() + len / 2);
    b.assign(input.begin() + len / 2, input.end());

    for(auto tmp1 : a) for(auto tmp2 : b){
        G[tmp1][tmp2] = num;
        G[tmp2][tmp1] = num;
    }
    num++;
    if (a.size() > 1) REC(G, a, num);
    if (b.size() > 1) REC(G, b, num);
    return 0;
}

int main() {

    int N;
    cin >> N;

    vector<vector<int>> G(N, vector<int>(N, -1));
    //cout << "Hi" << endl;
    vector<int> I;
    REP(i, N) I.push_back(i);
    //cout << "Hi" << endl;

    REC(G, I, 1);

    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}