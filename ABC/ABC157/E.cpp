
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

struct coun{
    vector<int> v;
    ll size;
    void update(char c, char c1){
        ll i = c - 'a';
        ll i1 = c1 - 'a';
        v[i]--;
        if (v[i] == 0) size--;
        if (v[i1] == 0) size++;
        v[i1]++;
    }
};
class BIT
{
public:
    vector<coun> bit;
    int M;

    BIT(int M):
        M(M), bit(M+1) {
            REP(i, M+1){
                vector<int> hoge(27, 0);
                bit[i].v = hoge;}
        }
    void set(int i, char c){
        if (i > M) return;
        int h = c - 'a';
        bit[i].v[h]++;
        set(i+(i&-i), c);

    }
    vector<int> sum(int i) {
        vector<int> vv(27, 0);
        if (!i) return vv;
        vv = sum(i-(i&-i));
        return mm(vv, bit[i].v);
    }

    void update(int i, char x, char y) {
        if (i > M) return;
        bit[i].update(x, y);
        update(i+(i&-i), x, y);
    }

    vector<int> mm(vector<int>& a, vector<int>& b){
    int n = a.size();
    vector<int> hoge(n, 0);
    REP(i, n) hoge[i] = a[i] + b[i];
    return hoge;
    }
};


int main() {
    ll N, Q;
    string S;
    cin >> N;
    cin >> S;
    cin >> Q;

    BIT B(N);
    REP(i, N){
        B.set(i+1, S[i]);

    }

    vector<int> ans;
    vector<int> v_l, v_r;
    ll mode, l, r;
    char c;
    REP(i, Q){
        cin >> mode;
        if (mode == 1) {
            cin >> l >> c;
            B.update(l, S[l-1], c);
            S[l - 1] = c;
            }

        else {
            cin >> l >> r;
            v_l = B.sum(l-1);
            v_r = B.sum(r);
            int tmp = 0;
            REP(i, 27) if (v_r[i] - v_l[i] > 0) tmp++;
            ans.push_back(tmp);
        }
    }

    REP(i, ans.size()) cout << ans[i] << endl;
    return 0;
}

