
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

template<class T> class bit {
public:
    vector<T> dat;
    int N;

    bit(){}
    bit(int N) : N(N) { dat.assign(N,0); }
    // sum [0,i)
    T sum(int i){
        int ret = 0;
        for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
        return ret;
    }
    // sum [i,j)
    T sum(int i, int j) { return sum(j) - sum(i); }
    // add x to i
    void add(int i, T x) { for(; i < N; i|=i+1) dat[i] += x; }
};


int main() {
      //std::ifstream in("02-small-00");
  //std::cin.rdbuf(in.rdbuf());

    ll N, Q;
    string S;
    cin >> N;
    cin >> S;
    cin >> Q;

    vector<bit<int>> b(27);
    REP(i, 27){
        bit<int> hoge = bit<int>(N);
        b[i] = hoge;
    }
    REP(i, N) b[S[i] - 'a'].add(i, 1);

    vector<int> ans;
    ll mode, l, r;
    char c;
    REP(i, Q){
        cin >> mode;
        if (mode == 1) {
            cin >> l >> c;
            char t = S[l-1];
            b[t - 'a'].add(l-1, -1);
            b[c - 'a'].add(l-1, 1);
            S[l - 1] = c;
            }

        else {
            cin >> l >> r;
            int tmp = 0;
            REP(i, 27) {
                if (b[i].sum(l - 1, r) > 0) 
                {
                    tmp++;
                    //cout << char('a' + i)  << " "<< b[i].sum(l - 2, r) << endl;
                    }
            }
            ans.push_back(tmp);
        }
    }

    REP(i, ans.size()) cout << ans[i] << endl;
    return 0;
}

