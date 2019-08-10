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
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    ll sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    vector<ll> cand;
    REP(i, sqrt(sum) + 1){
        if (i == 0) continue;
        if (sum % i == 0) {
            cand.push_back(sum / i);
            cand.push_back(i);
        }
    }
    sort(cand.begin(), cand.end(), std::greater<long long>());
    for(auto tmp: cand){
        vector<ll> mm;
        ll m_sum = 0;
        REP(i, N) {
            mm.push_back(A[i] % tmp);
            m_sum += A[i] % tmp;
        }
        sort(mm.begin(), mm.end());
        //cout << tmp << " ";
        //REP(i, mm.size()) cout << mm[i] << " ";
        //cout << endl;
        ll way = 0;
        if (m_sum % tmp != 0) continue;
        ll right = m_sum / tmp;
        for(ll i = 1; i <= right; i++){
            way += (tmp - *(mm.end() - i));
        }
        if (way <= K) {
            cout << tmp << endl;
            return 0;
        }

    }



    return 0;
}
